/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_EOF.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 15:08:59 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 23:57:28 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_eof(char *str)
{
	char	*str_tmp;
	int		i;

	i = ft_strlen(str);
	str_tmp = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i])
	{
		str_tmp[i] = str[i];
		i++;
	}
	str_tmp[i] = '\0';
	str_tmp[i + 1] = -1;
	str = ft_free(str);
	return (str_tmp);
}
