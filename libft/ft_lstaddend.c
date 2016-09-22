/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:48:10 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 15:58:34 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstaddend(t_list **list, t_list *lst)
{
	if (list && lst)
	{
		while ((*list)->next)
			*list = (*list)->next;
		(*list)->next = lst;
	}
}
