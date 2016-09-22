/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		get_cursor(char *command, t_lst *lst)
{
	tputs(tgetstr(command, &(lst->p)), 0, ft_outc);
	if (ft_strcmp(command, MVLEFT) == 0)
	{
		lst->index--;
		if (lst->pos_y <= 0)
		{
			lst->pos_y = lst->col - 1;
			lst->pos_x--;
		}
		else
			lst->pos_y--;
	}
	if (ft_strcmp(command, MVRIGHT) == 0)
	{
		lst->index++;
		if ((lst->pos_y >= (lst->col - 1)))
		{
			tputs(tgetstr("do", &(lst->p)), 0, ft_outc);
			tputs(tgetstr("cr", &(lst->p)), 0, ft_outc);
			lst->pos_y = 0;
			lst->pos_x++;
		}
		else
			lst->pos_y++;
	}
}
