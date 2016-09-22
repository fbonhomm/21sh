/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:35:00 by fbonhomm          #+#    #+#             */
/*   Updated: 2014/12/01 17:35:04 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_len(char const *s1, char const *s2)
{
	int		len;

	len = 0;
	if (s1)
		len = ft_strlen(s1);
	if (s2)
		len = len + ft_strlen(s2);
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;

	if ((s1 || s2))
	{
		i = 0;
		str = malloc(sizeof(char) * ft_calc_len(s1, s2) + 1);
		while (s1 && s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		len = i;
		i = 0;
		while (s2 && s2[i])
		{
			str[len + i] = s2[i];
			i++;
		}
		str[len + i] = '\0';
		return (str);
	}
	return (NULL);
}
