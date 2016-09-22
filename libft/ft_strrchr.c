/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:42:02 by fbonhomm          #+#    #+#             */
/*   Updated: 2014/12/01 17:42:06 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		length;
	char	*ptr;

	i = 0;
	length = ft_strlen(s);
	ptr = NULL;
	if ((char)c == '\0')
		return ((char *)(s + length));
	while (s[i])
	{
		if ((char)c == s[i])
			ptr = ((char *)(s + i));
		i++;
	}
	return (ptr);
}
