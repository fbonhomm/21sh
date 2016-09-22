/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:42:15 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/10/20 13:40:27 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbtab(const char *s, char c)
{
	int i;
	int nbr;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	nbr = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		nbr++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (nbr);
}

char			**ft_strsplit(const char *s, char c)
{
	int		index;
	int		j;
	char	**str;
	int		k;

	str = (char**)malloc(sizeof(char*) * (ft_nbtab(s, c) + 1));
	index = 0;
	j = 0;
	while (s[j] && (index < ft_nbtab(s, c)))
	{
		while (s[j] == c)
			j++;
		str[index] = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (str[index] == NULL)
			return (NULL);
		k = 0;
		while (s[j] != c && s[j])
			str[index][k++] = s[j++];
		str[index][k] = '\0';
		index++;
	}
	str[index] = NULL;
	return (str);
}
