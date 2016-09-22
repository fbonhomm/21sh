/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:49:07 by fbonhomm          #+#    #+#             */
/*   Updated: 2014/12/01 16:49:12 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list		*list_ptr_init;
	t_list		*new;
	t_list		*old;

	if (!list || !f)
		return (NULL);
	old = f(list);
	if (!old || !(new = ft_lstnew(old->content, old->content_size)))
		return (NULL);
	list_ptr_init = new;
	while (list->next)
	{
		old = f(list->next);
		if (old && (new->next = ft_lstnew(old->content, old->content_size)))
		{
			new = new->next;
			list = list->next;
		}
		else
			list = NULL;
	}
	return (list_ptr_init);
}
