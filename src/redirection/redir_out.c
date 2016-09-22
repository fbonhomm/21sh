/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		fork_redir_out(t_stc *stc, int j)
{
	if ((ft_strcmp(stc->redir[stc->out], ">") == 0) ||
			(ft_strcmp(stc->redir[stc->out], ">>") == 0))
		dup2(stc->fd_out, STDOUT_FILENO);
	if ((ft_strcmp(stc->redir[stc->in], "0>") == 0) ||
			(ft_strcmp(stc->redir[stc->in], "0>>") == 0))
		dup2(stc->fd_in, STDIN_FILENO);
	if ((ft_strcmp(stc->redir[stc->err], "2>") == 0) ||
			(ft_strcmp(stc->redir[stc->err], "2>>") == 0))
		dup2(stc->fd_err, STDERR_FILENO);
	fusion_fd(stc->redir[j - 1]);
}

void		loop_init_redir(t_stc *stc, int *j)
{
	while (stc->redir[*j])
	{
		if ((ft_strcmp(stc->redir[*j], ">") == 0) ||
				(ft_strcmp(stc->redir[*j], ">>") == 0))
			stc->out = *j;
		if ((ft_strcmp(stc->redir[*j], "2>") == 0) ||
				(ft_strcmp(stc->redir[*j], "2>>") == 0))
			stc->err = *j;
		if ((ft_strcmp(stc->redir[*j], "0>") == 0) ||
				(ft_strcmp(stc->redir[*j], "0>>") == 0))
			stc->in = *j;
		*j = *j + 1;
	}
}

void		open_file_out(char **tabl, int *fd, int i, int flag)
{
	DIR		*rep;

	if ((*fd = open(tabl[i + 1], O_WRONLY | O_CREAT | flag, 0644)) < 0)
	{
		if (errno == EISDIR)
			ft_print_str_endl(3, "21sh: ", tabl[i + 1], ": Is a directory\n");
		else if (access(tabl[i + 1], F_OK) == -1)
			ft_print_str_endl(3, "21sh: no such file or directory: ",
				tabl[i + 1], "\n");
		else if (access(tabl[i + 1], X_OK) == -1)
		{
			rep = opendir(tabl[i + 1]);
			if (errno == EACCES)
				ft_print_str_endl(3, "21sh: ", tabl[i + 1],
					": permission denied\n");
			else
				ft_print_str_endl(3, "21sh: ", tabl[i + 1],
					": Is a directory\n");
			closedir(rep);
		}
		close(*fd);
		exit(-1);
	}
}

void		redir_out(t_stc *stc, int *j)
{
	stc->out = 0;
	stc->in = 0;
	stc->err = 0;
	loop_init_redir(stc, j);
	if (ft_strcmp(stc->redir[stc->out], ">") == 0)
		open_file_out(stc->redir, &stc->fd_out, stc->out, O_TRUNC);
	if (ft_strcmp(stc->redir[stc->out], ">>") == 0)
		open_file_out(stc->redir, &stc->fd_out, stc->out, O_APPEND);
	if (ft_strcmp(stc->redir[stc->err], "2>") == 0)
		open_file_out(stc->redir, &stc->fd_err, stc->err, O_TRUNC);
	if (ft_strcmp(stc->redir[stc->err], "2>>") == 0)
		open_file_out(stc->redir, &stc->fd_err, stc->err, O_APPEND);
	if (ft_strcmp(stc->redir[stc->in], "0>") == 0)
		open_file_out(stc->redir, &stc->fd_in, stc->in, O_TRUNC);
	if (ft_strcmp(stc->redir[stc->in], "0>>") == 0)
		open_file_out(stc->redir, &stc->fd_in, stc->in, O_APPEND);
	fork_redir_out(stc, *j);
	*j = more_tall(stc->out, stc->in, stc->err);
}
