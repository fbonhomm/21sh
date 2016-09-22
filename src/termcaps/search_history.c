/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			insert_history(t_lst *lst, char *tmp, int fd)
{
	int		i;

	i = 0;
	while (lst->index > 0)
		get_cursor(MVLEFT, lst);
	tputs(tgetstr("ce", &(lst->p)), 0, ft_outc);
	ft_bzero(lst->buffer, MAX);
	while (tmp[i] && ft_strlen(lst->buffer) < MAX - 1)
	{
		create_line(lst, tmp[i]);
		print_line(lst, NULL);
		if (lst->pos_y > (lst->col))
		{
			lst->pos_y = 0;
			lst->pos_x++;
		}
		i++;
	}
	close(fd);
	return (1);
}

int			search_history(t_lst *lst)
{
	char	buf[1];
	char	tmp[MAX];
	int		fd;
	int		i;

	if ((fd = open(lst->path, O_RDONLY)))
	{
		i = 0;
		ft_bzero(tmp, MAX);
		while (read(fd, buf, 1) > 0)
		{
			if (buf[0] == '\n')
			{
				if ((ft_strncmp(lst->buffer, tmp, ft_strlen(lst->buffer))) == 0)
					return (insert_history(lst, tmp, fd));
				i = 0;
				ft_bzero(tmp, MAX);
			}
			else
				tmp[i++] = buf[0];
		}
		close(fd);
	}
	return (1);
}
