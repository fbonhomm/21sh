/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int					issprint(int c)
{
	if (((c >= 32) && (c <= 126)) || c == 9)
		return (1);
	return (0);
}

void				insert(t_lst *lst, t_stc *stc, char *buf)
{
	struct winsize	ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	lst->col = ws.ws_col;
	tputs(tgetstr("SA", &(lst->p)), 0, ft_outc);
	if (((!term_control(stc, lst, buf)) && ((issprint(buf[0])))))
	{
		if (ft_strlen(lst->buffer) < MAX - 1)
		{
			create_line(lst, buf[0]);
			print_line(lst, buf);
			if (lst->pos_y >= (lst->col))
			{
				lst->pos_y = 0;
				lst->pos_x++;
			}
		}
	}
}
