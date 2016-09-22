/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_read_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 17:18:05 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 17:24:21 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_in_read_line(char **line, t_env *env, int fd, char *buff)
{
	(*line)[env->j] = buff[env->i];
	env->j++;
	env->i++;
	if (buff[env->i] == '\0')
	{
		env->i = 0;
		ft_bzero(buff, SIZE + 1);
		if ((env->rd = read(fd, buff, SIZE)) > 0)
			*line = ft_realloc((void *)*line, ft_strlen(*line) + SIZE + 1);
		if (env->rd == 0)
			return (0);
		if (env->rd < 0)
			return (1);
	}
	return (2);
}
