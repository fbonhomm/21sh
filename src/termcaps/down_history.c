/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		parcour_down(t_lst *lst, int fd)
{
	char	buf[1];
	char	tmp[MAX];
	int		i;
	int		c;

	while (lst->index > 0)
		get_cursor(MVLEFT, lst);
	tputs(tgetstr("cd", &(lst->p)), 0, ft_outc);
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

void		reset_buffer(t_lst *lst)
{
	while (lst->index > 0)
		get_cursor(MVLEFT, lst);
	tputs(tgetstr("cd", &(lst->p)), 0, ft_outc);
	ft_bzero(lst->buffer, MAX);
	ft_strcpy(lst->buffer, lst->tmp_history);
}

int			down_history(t_lst *lst)
{
	int		fd;

	if (((fd = open(lst->path, O_RDONLY)) &&
		lst->index_history < lst->ind_hist_max))
	{
		lst->index_history++;
		if (lst->index_history < lst->ind_hist_max)
			parcour_down(lst, fd);
		else if (lst->index_history == (lst->ind_hist_max) &&
				ft_strcmp(lst->buffer, lst->tmp_history) != 0)
			reset_buffer(lst);
		else
		{
			close(fd);
			return (1);
		}
		print_line(lst, NULL);
		while (lst->buffer[lst->index])
			get_cursor(MVRIGHT, lst);
		close(fd);
	}
	return (1);
}
