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

void		create_line(t_lst *lst, char car)
{
	char	tmp[MAX];
	int		i;
	int		c;

	i = lst->index;
	ft_bzero(tmp, MAX);
	if (lst->buffer[0])
	{
		ft_strncpy(tmp, lst->buffer, i);
		tmp[i] = car;
		c = i;
		i++;
		while (lst->buffer[c])
			tmp[i++] = lst->buffer[c++];
		ft_bzero(lst->buffer, MAX);
		ft_strcpy(lst->buffer, tmp);
	}
	else
		lst->buffer[i] = car;
	lst->index++;
	lst->pos_y++;
}
