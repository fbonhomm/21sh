/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:48:23 by fbonhomm          #+#    #+#             */
/*   Updated: 2014/12/01 16:48:28 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **list, void (*del)(void *, size_t))
{
	t_list		*list_ptr;
	t_list		*save;

	if (del && list && *list)
	{
		list_ptr = *list;
		while (list_ptr != NULL)
		{
			save = list_ptr;
			list_ptr = list_ptr->next;
			ft_lstdelone(&save, del);
		}
	}
	*list = NULL;
}
