/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poin_vir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		message_err_redir(char *str, t_stc *stc)
{
	ft_print_str_endl(1, str);
	stc->red = 0;
	return (0);
}

int		search_redir(t_stc *stc, int i)
{
	int j;

	j = 0;
	stc->red = 0;
	while (stc->pipe[i][j])
	{
		if (((stc->pipe[i][j] == '>') || (stc->pipe[i][j] == '<')) &&
				(stc->pipe[i][j + 1] != '&'))
			stc->red = 1;
		if (stc->pipe[i][j] == '>' && stc->pipe[i][j + 1] == '>' &&
				stc->pipe[i][j + 2] == '>')
			return (message_err_redir("21sh: parse error near `>'\n", stc));
		if (stc->pipe[i][j] == '<' && stc->pipe[i][j + 1] == '<' &&
				stc->pipe[i][j + 2] == '<')
			return (message_err_redir("21sh: parse error near `<'\n", stc));
		j++;
	}
	return (1);
}
