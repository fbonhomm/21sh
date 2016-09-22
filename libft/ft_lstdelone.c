/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:48:37 by fbonhomm          #+#    #+#             */
/*   Updated: 2014/12/01 16:48:44 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdelone(t_list **list, void (*del)(void*, size_t))
{
	if (*list && *del && list)
	{
		del((*list)->content, (*list)->content_size);
		free(*list);
		*list = NULL;
	}
}
