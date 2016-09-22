/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 16:49:21 by fbonhomm          #+#    #+#             */
/*   Updated: 2014/12/01 16:49:24 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_list;
	void		*str;

	new_list = malloc(sizeof(t_list));
	str = NULL;
	if (new_list == NULL)
		return (NULL);
	if (!content)
	{
		content = NULL;
		content_size = 0;
	}
	else
	{
		str = malloc(sizeof(content) * content_size);
		if (str == NULL)
			return (NULL);
		ft_memcpy(str, content, content_size);
	}
	new_list->next = NULL;
	new_list->content = str;
	new_list->content_size = content_size;
	return (new_list);
}
