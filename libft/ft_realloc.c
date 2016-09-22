/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 17:06:28 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/08 17:03:31 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc(char **str, size_t size)
{
	char	*ret;
	size_t	len;

	if (!*str)
		return (malloc(size));
	len = ft_strlen(*str);
	if ((ret = (char*)malloc(sizeof(char) * (size + len))))
	{
		ft_bzero(ret, len);
		ft_strncpy(ret, *str, len);
		*str = ft_free(*str);
		return (ret);
	}
	return (NULL);
}
