/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auto_compl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:13:39 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 17:59:14 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int		nbtab(char const *s, char c, char d)
{
	int			i;
	int			nbr;

	i = 0;
	while ((s[i] == c && s[i]) || (s[i] == d && s[i]))
		i++;
	nbr = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c && s[i] != d)
			i++;
		nbr++;
		while ((s[i] && s[i] == c) || (s[i] && s[i] == d))
			i++;
	}
	return (nbr);
}

void			loop_split(char const *s, char **str, int *j, int *index)
{
	int			booleen;
	int			k;
	char		car;

	booleen = 0;
	k = 0;
	while ((s[*j] == ' ') || (s[*j] == '\t'))
		*j = *j + 1;
	str[*index] = ft_strnew(ft_strlen(s));
	while ((s[*j] && s[*j] != ' ' && s[*j] != '\t') || (booleen == 1))
	{
		if (((s[*j] == '\"' && booleen == 0) ||
			(s[*j] == '\'' && booleen == 0)))
		{
			booleen = 1;
			car = s[*j];
		}
		else if ((booleen == 1 && s[*j] == car))
			booleen = 0;
		else
			str[*index][k++] = s[*j];
		*j = *j + 1;
	}
	str[*index][k] = '\0';
	*index = *index + 1;
}

char			**ft_split_quote(char const *s)
{
	int			len;
	int			j;
	int			index;
	char		**str;

	j = 0;
	index = 0;
	len = nbtab(s, ' ', '\t');
	if ((!s) || (!(str = (char**)malloc(sizeof(char*) * (len + 1)))))
		return (NULL);
	while (s[j] && (index < len))
		loop_split(s, str, &j, &index);
	str[index] = NULL;
	return (str);
}
