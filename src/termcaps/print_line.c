/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:15:31 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/04/25 18:15:34 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		position_cursor(t_lst *lst, int len)
{
	int		i;
	int		c;
	int		col;

	i = lst->pos_y;
	c = lst->pos_x;
	col = lst->col;
	len = len + i;
	while (i < len)
	{
		if (i >= col)
		{
			col = col + lst->col;
			c++;
		}
		i++;
	}
	while (c > lst->pos_x)
	{
		tputs(tgetstr("up", &(lst->p)), 0, ft_outc);
		c--;
	}
	tputs(tgoto(tgetstr("ch", &(lst->p)), 0, lst->pos_y), 0, ft_outc);
}

void		print_line(t_lst *lst, char *buf)
{
	int		i;
	int		c;
	int		len;
	char	tmp[MAX];

	if (lst->index != 0)
		i = lst->index - 1;
	else
		i = 0;
	if (buf && DEL)
		i = lst->index;
	c = 0;
	ft_bzero(tmp, MAX);
	while (lst->buffer[i])
		tmp[c++] = lst->buffer[i++];
	len = ft_strlen(tmp);
	tputs(tgetstr("cd", &(lst->p)), 0, ft_outc);
	write(1, &tmp, len + 1);
	if (((lst->pos_y + len) > (lst->col + 1) && lst->pos_y < lst->col) ||
			((lst->pos_y + len) >= (lst->col - 1) && buf && DEL))
		position_cursor(lst, len);
	else if (lst->pos_y < lst->col && lst->buffer[lst->index])
		tputs(tgoto(tgetstr("ch", &(lst->p)), 0, lst->pos_y), 0, ft_outc);
	else if (lst->pos_y >= lst->col && lst->buffer[lst->index])
		tputs(tgoto(tgetstr("ch", &(lst->p)), 0, 0), 0, ft_outc);
}
