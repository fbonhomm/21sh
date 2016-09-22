/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			switch_term(t_lst *lst)
{
	if (lst->index_color == 0)
		lst->index_color = 1;
	else if (lst->index_color == 1)
		lst->index_color = 0;
	return (1);
}
