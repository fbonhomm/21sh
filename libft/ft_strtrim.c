/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:42:54 by fbonhomm          #+#    #+#             */
/*   Updated: 2014/12/01 17:42:59 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		var[4];
	char	*str;

	if (s)
	{
		var[0] = 0;
		while (s[var[0]] == ' ' || s[var[0]] == '\n' || s[var[0]] == '\t')
			var[0]++;
		var[1] = ft_strlen(s) - 1;
		while ((s[var[1]] == ' ' || s[var[1]] == '\n' || \
					s[var[1]] == '\t') && var[1] > var[0])
			var[1]--;
		if ((str = malloc(sizeof(char) * var[1] - var[0] + 1)) == NULL)
			return (NULL);
		var[2] = 0;
		while (var[0] <= var[1])
		{
			str[var[2]] = s[var[0]];
			var[2]++;
			var[0]++;
		}
		str[var[2]] = '\0';
		return (str);
	}
	return (NULL);
}
