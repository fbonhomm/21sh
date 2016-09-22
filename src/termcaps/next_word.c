/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		next_word(t_lst *lst)
{
	if (lst->buffer[lst->index] != ' ')
	{
		while (lst->buffer[lst->index] && lst->buffer[lst->index] != ' ')
			get_cursor(MVRIGHT, lst);
		while (lst->buffer[lst->index] && lst->buffer[lst->index] == ' ')
			get_cursor(MVRIGHT, lst);
	}
	else if (lst->buffer[lst->index] == ' ')
	{
		while (lst->buffer[lst->index] && lst->buffer[lst->index] == ' ')
			get_cursor(MVRIGHT, lst);
	}
	return (1);
}
