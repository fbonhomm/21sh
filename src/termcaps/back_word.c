/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		back_word(t_lst *lst)
{
	if (lst->index - 1 >= 0 && lst->buffer[lst->index - 1] != ' ')
	{
		while (lst->index - 1 >= 0 && lst->buffer[lst->index - 1] != ' ')
			get_cursor(MVLEFT, lst);
	}
	else if (lst->index - 1 >= 0 && lst->buffer[lst->index - 1] == ' ')
	{
		while (lst->index - 1 >= 0 && lst->buffer[lst->index - 1] == ' ')
			get_cursor(MVLEFT, lst);
		while (lst->index - 1 >= 0 && lst->buffer[lst->index - 1] != ' ')
			get_cursor(MVLEFT, lst);
	}
	return (1);
}
