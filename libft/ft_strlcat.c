/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:35:12 by fbonhomm          #+#    #+#             */
/*   Updated: 2014/12/01 17:35:19 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*ptr;
	char	*rd;
	size_t	len;

	ptr = ft_memchr(dst, '\0', size);
	rd = (char *)src;
	len = (size_t)(ptr - dst) + ft_strlen(rd);
	if (ptr == NULL)
		return (size + ft_strlen(src));
	while ((size_t)(ptr - dst) < size - 1 && *rd != '\0')
	{
		*ptr = *rd;
		ptr++;
		rd++;
	}
	*ptr = '\0';
	return (len);
}
