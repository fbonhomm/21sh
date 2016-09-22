/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			paste(t_lst *lst)
{
	char	buf[10];
	int		i;

	i = 0;
	ft_bzero(buf, 10);
	while (lst->clipboard[i] && ft_strlen(lst->buffer) < MAX - 1)
	{
		create_line(lst, lst->clipboard[i]);
		print_line(lst, NULL);
		if (lst->pos_y >= (lst->col))
		{
			lst->pos_y = 0;
			lst->pos_x++;
		}
		i++;
	}
	return (1);
}
