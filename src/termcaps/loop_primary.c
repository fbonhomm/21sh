/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_primary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/08 17:34:56 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			ft_outc(int c)
{
	return ((int)write(STDIN_FILENO, &c, 1));
}

void		enter(t_lst *lst, t_stc *stc)
{
	while (lst->buffer[lst->index + 1])
		get_cursor(MVRIGHT, lst);
	ft_putchar('\n');
	stc->buf = ft_free(stc->buf);
	stc->buf = ft_strdup(lst->buffer);
	if ((parenthese(lst, stc)) == 1)
	{
		tputs(tgetstr("ei", &(lst->p)), 0, ft_outc);
		if (ft_strlen(stc->buf) < MAX)
			ft_strcpy(lst->buffer, stc->buf);
		else
			ft_bzero(lst->buffer, MAX);
		open_history(lst);
		count_history(lst);
		ft_bzero(lst->tmp_history, MAX);
		init_standard();
		env_to_stc(stc);
		ft_check(stc, lst);
		tputs(tgetstr("im", &(lst->p)), 0, ft_outc);
	}
	stc->buf = ft_free(stc->buf);
	if (stc->ctrl_c == 0)
		prompt(stc, lst, 0);
	ft_bzero(lst->buffer, MAX);
	lst->index = 0;
}

void		init_var_term(t_lst *lst)
{
	ft_bzero(lst->buffer, MAX);
	ft_bzero(lst->clipboard, MAX);
	ft_bzero(lst->tmp_compl, MAX);
	lst->index = 0;
	lst->pos_x = 0;
	lst->index_color = 0;
	lst->p = NULL;
}

void		loop_primary(t_stc *stc, t_lst *lst)
{
	char	buf[100];

	init_var_term(lst);
	pwd_history(lst);
	count_history(lst);
	prompt(stc, lst, 0);
	while (42)
	{
		init_termios();
		signal_stc(stc);
		signal_lst(lst);
		ft_bzero(buf, 100);
		read(STDIN_FILENO, buf, 100);
		stc->ctrl_c = 0;
		if ((buf[0] == 4 && buf[1] == 0))
			end(stc, 0);
		if (conform(buf))
		{
			prompt(NULL, NULL, 0);
			if (ENTER)
				enter(lst, stc);
			else
				insert(lst, stc, buf);
		}
	}
}
