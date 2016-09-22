/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:35:00 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/07 19:36:28 by fbonhomm         ###   ########.fr       */
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

char		*ft_strjoin_and_free(char **s1, char *s2)
{
	char	*str;
	int		len;
	int		i;

	if ((*s1 || s2))
	{
		i = 0;
		str = malloc(sizeof(char) * ft_calc_len(*s1, s2) + 1);
		while (*s1 && *s1[i])
		{
			str[i] = *s1[i];
			i++;
		}
		len = i;
		i = 0;
		while (s2 && s2[i])
		{
			str[len + i] = s2[i];
			i++;
		}
		*s1 = ft_free(*s1);
		str[len + i] = '\0';
		return (str);
	}
	if (s2)
		return (ft_strdup(s2));
	if (*s1)
		return (*s1);
	return (NULL);
}
