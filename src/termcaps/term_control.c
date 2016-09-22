/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			valid_tab(t_lst *lst)
{
	int		i;

	i = -1;
	if (!lst->buffer[0])
		return (0);
	while (lst->buffer[++i])
	{
		if ((lst->buffer[i] >= 33) && (lst->buffer[i] <= 126))
			return (1);
	}
	return (0);
}

int			suite_term_control(t_lst *lst, char *buf)
{
	if (CTRLW && lst->buffer[0])
		return (back_word(lst));
	else if (CTRLE && lst->buffer[lst->index])
		return (next_word(lst));
	else if (DEL)
		return (del(lst, buf));
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59 &&
				buf[4] == 50 && buf[5] == 67 && buf[6] == 0)
		return (underline(lst, buf));
	else if ((HOME) || (END))
		return (start_and_end(lst, buf));
	else if ((buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59 &&
buf[4] == 50 && buf[5] == 65 && buf[6] == 0) || (buf[0] == 27 && buf[1] == 91 &&
buf[2] == 49 && buf[3] == 59 && buf[4] == 50 && buf[5] == 66 && buf[6] == 0))
		return (up_and_down(lst, buf));
	else if (CTRLP)
		return (paste(lst));
	else if (CTRLR)
		return (search_history(lst));
	else if (TAB && valid_tab(lst))
		return (autocompletion(lst));
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 54 &&
				buf[3] == 126 && buf[4] == 0)
		return (switch_term(lst));
	return (0);
}

int			term_control(t_stc *stc, t_lst *lst, char *buf)
{
	if (CTRLL)
	{
		tputs(tgetstr(CLEAR, &(lst->p)), 0, ft_outc);
		prompt(stc, lst, 0);
		print_line(lst, NULL);
		while (lst->buffer[lst->index])
			get_cursor(MVRIGHT, lst);
	}
	else if (UP)
		return (up_history(lst));
	else if (DOWN)
		return (down_history(lst));
	else if (LEFT && lst->index > 0)
		get_cursor(MVLEFT, lst);
	else if (RIGHT && lst->buffer[lst->index])
		get_cursor(MVRIGHT, lst);
	else if ((suite_term_control(lst, buf)) == 1)
		return (1);
	else
		return (0);
	return (1);
}
