/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void			loop_pipe(t_stc *stc, int *j, t_lst *lst)
{
	int			fd[2];
	pid_t		pid;

	stc->command = ft_split_quote(stc->pipe[*j]);
	tilde(stc, &stc->command);
	if ((pipe(fd) == 0) && (pid = fork()) == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		if ((search_redir(stc, *j)))
		{
			if (stc->red)
				ft_redir_pipe(stc, *j, lst);
			if (!ft_builtin(stc))
				execve_binary(stc);
		}
		exit(0);
	}
	if (stc->ctrl_c == 1)
		exit(0);
	wait(NULL);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	stc->command = ft_free_array(stc->command);
	*j = *j + 1;
}

void			ft_pipe(t_stc *stc, t_lst *lst)
{
	int			j;
	int			status;
	pid_t		pid;

	j = 0;
	pid = fork();
	if (pid == 0)
	{
		stc->command = ft_free_array(stc->command);
		while ((stc->pipe[j + 1]))
			loop_pipe(stc, &j, lst);
		stc->command = ft_split_quote(stc->pipe[j]);
		if ((search_redir(stc, j)))
		{
			if (stc->red)
				ft_redir_pipe(stc, j, lst);
			if (!ft_builtin(stc))
				execve_binary(stc);
		}
		stc->command = ft_free_array(stc->command);
		exit(0);
	}
	waitpid(pid, &status, 0);
	stc->command = ft_free_array(stc->command);
}
