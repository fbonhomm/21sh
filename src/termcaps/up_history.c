/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		save_buffer(t_lst *lst)
{
	ft_bzero(lst->tmp_history, MAX);
	ft_strcpy(lst->tmp_history, lst->buffer);
}

void		parcour_up(t_lst *lst, int fd)
{
	char	buf[1];
	char	tmp[MAX];
	int		i;
	int		c;

	i = 0;
	while (i <= lst->index_history)
	{
		c = 0;
		ft_bzero(tmp, MAX);
		while (read(fd, buf, 1) > 0 && buf[0] != '\n' && (c < MAX - 1))
			tmp[c++] = buf[0];
		i++;
	}
	ft_bzero(lst->buffer, MAX);
	ft_strcpy(lst->buffer, tmp);
}

int			up_history(t_lst *lst)
{
	int		fd;

	if (((fd = open(lst->path, O_RDONLY)) &&
		lst->index_history <= lst->ind_hist_max) && lst->index_history > 0)
	{
		lst->index_history--;
		if (lst->index_history == lst->ind_hist_max - 1)
			save_buffer(lst);
		while (lst->index > 0)
			get_cursor(MVLEFT, lst);
		parcour_up(lst, fd);
		print_line(lst, NULL);
		while (lst->buffer[lst->index])
			get_cursor(MVRIGHT, lst);
		close(fd);
	}
	return (1);
}
