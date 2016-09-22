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

int		message_err_pipe(char *str, t_stc *stc)
{
	ft_print_str_endl(1, str);
	stc->pip = 0;
	return (-1);
}

int		search_pipe(t_stc *stc, int i)
{
	int j;

	j = 0;
	stc->pip = 0;
	while (stc->separator[i][j])
	{
		if (stc->separator[i][j] == '|')
			stc->pip = 1;
		if (stc->separator[i][j] == '|' && stc->separator[i][j + 1] == '|')
			return (message_err_pipe("21sh: parse error near `|'\n", stc));
		else
			j++;
	}
	return (1);
}
