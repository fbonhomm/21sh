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

void		separator(t_stc *stc)
{
	if (stc->pv && stc->et)
		stc->separator = ft_split(stc->buf, ';', '&');
	else if (stc->pv)
		stc->separator = ft_strsplit(stc->buf, ';');
	else if (stc->et)
		stc->separator = ft_strsplit(stc->buf, '&');
	else
	{
		stc->separator = (char**)malloc(sizeof(char*) * 2);
		stc->separator[0] = ft_strdup(stc->buf);
		stc->separator[1] = NULL;
	}
}
