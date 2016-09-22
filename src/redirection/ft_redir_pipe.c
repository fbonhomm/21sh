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

void		ft_redir_pipe(t_stc *stc, int i, t_lst *lst)
{
	int			j;

	split_redir(stc, i);
	j = 0;
	while (stc->redir[j])
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
		j++;
	}
}
