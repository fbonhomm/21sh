/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		close_fd(t_stc *stc)
{
	close(stc->fd_in);
	close(stc->fd_out);
	close(stc->fd_err);
}

int			more_tall(int out, int in, int err)
{
	if (out >= in && out >= err)
		return (out + 1);
	if (in >= out && in >= err)
		return (in + 1);
	if (err >= in && err >= out)
		return (err + 1);
	return (0);
}

int			ft_valid(t_stc *stc, int i)
{
	if ((ft_strcmp(stc->redir[i], ">") == 0) ||
		(ft_strcmp(stc->redir[i], ">>") == 0) ||
			(ft_strcmp(stc->redir[i], "0>") == 0) ||
				(ft_strcmp(stc->redir[i], "2>") == 0) ||
					(ft_strcmp(stc->redir[i], "0>>") == 0) ||
						(ft_strcmp(stc->redir[i], "2>>") == 0))
		return (1);
	if ((ft_strcmp(stc->redir[i], "<") == 0) ||
			(ft_strcmp(stc->redir[i], "1<") == 0) ||
				(ft_strcmp(stc->redir[i], "2<") == 0))
		return (2);
	if ((ft_strcmp(stc->redir[i], "<<") == 0) ||
			(ft_strcmp(stc->redir[i], "1<<") == 0) ||
				(ft_strcmp(stc->redir[i], "2<<") == 0))
		return (3);
	return (0);
}

void		have_redir(t_stc *stc)
{
	int		i;

	i = 0;
	while (stc->redir[i])
	{
		if ((ft_strcmp(stc->redir[i], "<<") == 0) ||
				(ft_strcmp(stc->redir[i], "0<<") == 0) ||
					(ft_strcmp(stc->redir[i], "2<<") == 0) ||
						(ft_valid(stc, i) != 2 && ft_valid(stc, i) != 0))
			stc->redir_out = 1;
		i++;
	}
}

void		ft_redir(t_stc *stc, int i, int j, t_lst *lst)
{
	pid_t	pid;

	split_redir(stc, i);
	if ((pid = fork()) == 0)
	{
		while (stc->redir[++j])
		{
			tilde(stc, &stc->redir);
			if (ft_valid(stc, j) == 1)
				redir_out(stc, &j);
			else if (ft_valid(stc, j) == 2)
				redir_in(stc, &j);
			else if (ft_valid(stc, j) == 3)
			{
				if ((heredoc(stc, &j, lst)) == 0)
					exit(0);
			}
		}
		stc->redir = ft_free_array(stc->redir);
		if (!ft_builtin(stc))
			execve_binary(stc);
		exit(0);
	}
	wait(NULL);
	stc->redir = ft_free_array(stc->redir);
}
