/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 23:38:47 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/18 17:47:01 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int				ft_builtin(t_stc *stc)
{
	if ((ft_strcmp(stc->command[0], "exit")) == 0)
		return (ft_option_1(stc));
	else if (stc->command[0] && (ft_strcmp(stc->command[0], "cd")) == 0)
		return (ft_option_2(stc));
	else if (stc->command[0] && (ft_strcmp(stc->command[0], "setenv")) == 0)
		return (ft_option_3(stc));
	else if (stc->command[0] && (ft_strcmp(stc->command[0], "unsetenv")) == 0)
		return (ft_option_4(stc));
	else if (stc->command[0] && (ft_strcmp(stc->command[0], "env")) == 0)
		return (ft_option_5(stc));
	else
		return (0);
	return (1);
}

void			ft_check(t_stc *stc, t_lst *lst)
{
	int			ret;
	int			pip;
	int			i;

	if (stc->buf && stc->buf[0] != '\n')
	{
		i = 0;
		ret = search_separ(stc);
		separator(stc);
		while (stc->separator[i] && ret)
		{
			stc->command = ft_free_array(stc->command);
			pip = search_pipe(stc, i);
			split_pipe(stc, i);
			if (stc->pip)
				ft_pipe(stc, lst);
			else if (pip)
				ft_not_pipe(stc, lst);
			stc->pipe = ft_free_array(stc->pipe);
			i++;
		}
		stc->separator = ft_free_array(stc->separator);
	}
	stc->buf = ft_free(stc->buf);
	env_to_stc(stc);
}

void			get_signal(int i)
{
	t_stc		*stc;
	t_lst		*lst;

	stc = signal_stc(NULL);
	lst = signal_lst(NULL);
	stc->ctrl_c = 1;
	if (i == 2)
		ft_putstr("^C\n");
	if (i == 18)
		ft_putstr("^Z\n");
	if (i == 3)
		ft_putstr("^Q\n");
	ft_bzero(lst->buffer, MAX);
	prompt(stc, lst, 1);
}

int				main(int ac, char **av, char **env)
{
	t_stc		stc;
	t_lst		lst;

	(void)ac;
	(void)av;
	init(&stc, env);
	if (tgetent(NULL, getenv("TERM")) == (-1))
		no_env();
	tcgetattr(0, &g_old_term);
	welcome();
	signal(SIGINT, get_signal);
	signal(SIGQUIT, get_signal);
	signal(SIGTSTP, get_signal);
	env_to_stc(&stc);
	tputs(tgetstr("im", &(lst.p)), 0, ft_outc);
	loop_primary(&stc, &lst);
	return (0);
}
