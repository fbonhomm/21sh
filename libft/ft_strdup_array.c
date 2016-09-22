/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 14:07:21 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/10/12 14:07:23 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_len_array(char **str)
{
	int		x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char		**ft_strdup_array(char **tab)
{
	char	**ret;
	int		i;

	i = 0;
	ret = NULL;
	if (!tab)
		return (NULL);
	ret = (char**)malloc(sizeof(char*) * (ft_len_array(tab) + 2));
	while (tab[i])
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
