/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str_nocasse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:46:50 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 23:46:53 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_free_and_return(char *s3, int i)
{
	s3 = ft_free(s3);
	return (i);
}

int			ft_sort_str_nocasse(char *s1, char *s2)
{
	int		i;
	char	*s3;

	i = 0;
	if (ft_strlen(s1) > ft_strlen(s2))
		s3 = ft_strdup(s2);
	else
		s3 = ft_strdup(s1);
	while (s3[i])
	{
		if (ft_tolower(s1[i]) > ft_tolower(s2[i]))
			return (ft_free_and_return(s3, 1));
		if (ft_tolower(s1[i]) < ft_tolower(s2[i]))
			return (ft_free_and_return(s3, 2));
		i++;
	}
	if (ft_strlen(s1) > ft_strlen(s2))
		return (ft_free_and_return(s3, 1));
	return (ft_free_and_return(s3, 2));
}
