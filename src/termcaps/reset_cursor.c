/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_cursor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		reset_cusor(t_lst *lst, int len)
{
	int		index;
	int		pos;

	pos = lst->pos_y;
	index = lst->pos_y;
	while (index < (pos + len))
	{
		if ((lst->pos_y >= (lst->col - 1)))
		{
			lst->pos_y = 0;
			lst->pos_x++;
		}
		else
			lst->pos_y++;
		lst->index++;
		index++;
	}
}
