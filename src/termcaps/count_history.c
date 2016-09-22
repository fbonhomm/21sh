/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		count_history(t_lst *lst)
{
	char	buf[1];
	int		fd;

	lst->index_history = 0;
	lst->ind_hist_max = 0;
	if ((fd = open(lst->path, O_RDONLY)))
	{
		while (read(fd, buf, 1) > 0)
		{
			if (buf[0] == '\n')
				lst->index_history++;
		}
		lst->ind_hist_max = lst->index_history;
		close(fd);
	}
	ft_bzero(lst->tmp_history, MAX);
}
