/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void				pwd_history(t_lst *lst)
{
	char			tmp[10];
	int				len;
	int				i;

	i = 0;
	ft_bzero(lst->path, MAX);
	ft_bzero(tmp, 10);
	getcwd(lst->path, MAX);
	len = ft_strlen(lst->path);
	ft_strcpy(tmp, "/history");
	while (tmp[i])
		lst->path[len++] = tmp[i++];
}
