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

void		aggre_fd(t_stc *stc)
{
	int		i;

	i = 0;
	while (stc->command[i])
		i++;
	if (fusion_fd(stc->command[i - 1]) == 1)
		stc->command[i - 1] = ft_free(stc->command[i - 1]);
}

void		ft_not_pipe(t_stc *stc, t_lst *lst)
{
	pid_t	pid;

	if ((search_redir(stc, 0)))
	{
		if (stc->red)
			ft_redir(stc, 0, -1, lst);
		else
		{
			if ((stc->command = ft_split_quote(stc->pipe[0])))
			{
				tilde(stc, &stc->command);
				if (!ft_builtin(stc))
				{
					if ((pid = fork()) == 0)
					{
						aggre_fd(stc);
						execve_binary(stc);
						exit(0);
					}
					wait(NULL);
				}
			}
			stc->command = ft_free_array(stc->command);
		}
	}
}
