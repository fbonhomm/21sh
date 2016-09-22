/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitMult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 16:25:08 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/10/13 16:25:18 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbtab(char const *str, char *c)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	nb = 1;
	while (str[i])
	{
		while (c[j])
		{
			if (str[i] == c[j])
			{
				nb++;
				i = ft_search_false(str, c, i);
				j = 0;
			}
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (nb);
}

char		**ft_tab(char **tab, char const *str, char *c)
{
	int		i;
	int		k;
	int		nb;
	int		index;

	k = 0;
	index = 0;
	i = 0;
	while (str[i])
	{
		i = ft_search_false(str, c, i);
		nb = ft_search_true(str, c, i);
		if (nb != 0)
		{
			tab[index] = (char*)malloc(sizeof(char) * (nb + 1));
			while (str[i] && k < nb)
				tab[index][k++] = str[i++];
			tab[index][k] = '\0';
			k = 0;
			index++;
		}
	}
	tab[index] = NULL;
	return (tab);
}

char		**ft_split_(char **tab, char const *str, char *c, int i)
{
	tab = (char**)malloc(sizeof(*tab) * (i + 1));
	ft_tab(tab, str, c);
	return (tab);
}

char		**ft_none_chara(char **tab, char const *str)
{
	tab = (char**)malloc(sizeof(*tab) * (2));
	tab[0] = ft_strdup(str);
	tab[1] = NULL;
	return (tab);
}

char		**ft_split_mult(int nb, char const *str, ...)
{
	char	**tab;
	char	*c;
	int		i;
	va_list ap;

	tab = NULL;
	va_start(ap, str);
	i = 0;
	if (!str)
		return (NULL);
	c = (char*)malloc(sizeof(char) * nb);
	i = 0;
	while (i < nb)
		c[i++] = va_arg(ap, int);
	c[i] = '\0';
	va_end(ap);
	if ((i = ft_nbtab(str, c)) == 1)
	{
		tab = ft_none_chara(tab, str);
		return (tab);
	}
	tab = ft_split_(tab, str, c, i);
	c = ft_free(c);
	return (tab);
}
