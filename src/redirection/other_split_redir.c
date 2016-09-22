/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:01:46 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/04/25 18:01:55 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		ft_count_tab(t_stc *stc, int index)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (stc->pipe[index][i])
	{
		if ((stc->pipe[index][i] == '>') || (stc->pipe[index][i] == '<') ||
				(stc->pipe[index][i] == ' '))
			count++;
		i++;
	}
	stc->redir = (char**)malloc(sizeof(char*) * (count + 1));
	i = 0;
	while (i <= count)
		stc->redir[i++] = (char*)malloc(sizeof(char) * (count + 1));
}

void		condition_loop(t_stc *stc, int *a, int *b)
{
	if (*b != 0)
	{
		stc->redir[*a][*b] = '\0';
		*a = *a + 1;
		*b = 0;
	}
}
