/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_and_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			position_up(t_lst *lst, int i, int y, int x)
{
	tputs(tgetstr("up", &(lst->p)), 0, ft_outc);
	lst->index = i;
	lst->pos_y = y;
	lst->pos_x = x;
	return (1);
}

int			up(t_lst *lst)
{
	int		x;
	int		y;
	int		i;

	if (lst->pos_x > 0)
	{
		x = lst->pos_x;
		y = lst->pos_y;
		i = lst->index;
		while (i >= 0 && x >= lst->pos_x - 1)
		{
			if (x == lst->pos_x - 1 && y == lst->pos_y)
				return (position_up(lst, i, y, x));
			if (y <= 0)
			{
				y = lst->col - 1;
				x--;
			}
			else
				y--;
			i--;
		}
	}
	return (1);
}

int			position_down(t_lst *lst, int i, int y, int x)
{
	tputs(tgetstr("do", &(lst->p)), 0, ft_outc);
	tputs(tgoto(tgetstr("ch", &(lst->p)), 0, y), 0, ft_outc);
	lst->index = i;
	lst->pos_y = y;
	lst->pos_x = x;
	return (1);
}

int			down(t_lst *lst)
{
	int		x;
	int		y;
	int		i;

	x = lst->pos_x;
	y = lst->pos_y;
	i = lst->index;
	while (lst->buffer[i] && x <= lst->pos_x + 1)
	{
		if (x == lst->pos_x + 1 && y == lst->pos_y)
			return (position_down(lst, i, y, x));
		if ((y >= (lst->col - 1)))
		{
			y = 0;
			x++;
		}
		else
			y++;
		i++;
	}
	return (1);
}

int			up_and_down(t_lst *lst, char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59 &&
			buf[4] == 50 && buf[5] == 65 && buf[6] == 0)
		return (up(lst));
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59 &&
			buf[4] == 50 && buf[5] == 66 && buf[6] == 0)
		return (down(lst));
	return (1);
}
