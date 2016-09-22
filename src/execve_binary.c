/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:51:26 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/27 16:51:40 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	ft_join_path(t_stc *stc, char *path, int i)
{
	stc->tmp = ft_free(stc->tmp);
	stc->tmp = ft_strjoin_mult(3, path, "/", stc->command[0]);
	if (i == 1)
		execve(stc->tmp, stc->command, NULL);
}

void	execve_binary(t_stc *stc)
{
	int i;

	i = 0;
	stc->tmp = ft_free(stc->tmp);
	stc->tmp = ft_strdup(stc->command[0]);
	execve(stc->tmp, stc->command, stc->env);
	while ((stc->path && stc->path[i]))
	{
		ft_join_path(stc, stc->path[i], 0);
		execve(stc->tmp, stc->command, stc->env);
		i++;
	}
	ft_join_path(stc, stc->pwd, 1);
	ft_print_str_endl(3, "21sh: command not found: ", stc->command[0], "\n");
	stc->tmp = ft_free(stc->tmp);
	exit(-1);
}
