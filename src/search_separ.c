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

int		message_err(char *str, t_stc *stc)
{
	ft_print_str_endl(1, str);
	stc->pv = 0;
	stc->et = 0;
	return (-1);
}

int		check_et_logique(t_stc *stc, int i)
{
	int	index;

	index = 0;
	while (stc->buf[i++] == '&')
		index++;
	if (index >= 3)
		return (message_err("21sh: parse error near `&&'\n", stc));
	if (index == 2)
		stc->et = 1;
	return (i);
}

int		search_separ(t_stc *stc)
{
	int i;

	i = 0;
	stc->pv = 0;
	stc->et = 0;
	while (stc->buf[i])
	{
		if (stc->buf[i] == ';')
			stc->pv = 1;
		if (stc->buf[i] == ';' && stc->buf[i + 1] == ';')
			return (message_err("21sh: parse error near `;;'\n", stc));
		if (stc->buf[i] == '&')
		{
			if ((i = check_et_logique(stc, i)) == -1)
				return (0);
		}
		else
			i++;
	}
	return (1);
}
