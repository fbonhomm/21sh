/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_and_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			start_and_end(t_lst *lst, char *buf)
{
	if (HOME)
	{
		while (lst->index)
			get_cursor(MVLEFT, lst);
	}
	if (END)
	{
		while (lst->buffer[lst->index])
			get_cursor(MVRIGHT, lst);
	}
	return (1);
}
