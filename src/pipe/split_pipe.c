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

void		split_pipe(t_stc *stc, int i)
{
	if (stc->pip)
		stc->pipe = ft_strsplit(stc->separator[i], '|');
	else
	{
		stc->pipe = (char**)malloc(sizeof(char*) * 2);
		stc->pipe[0] = ft_strdup(stc->separator[i]);
		stc->pipe[1] = NULL;
	}
}
