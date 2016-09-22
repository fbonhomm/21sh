/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		valid(t_lst *lst)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (lst->buffer[i])
	{
		if (lst->buffer[i] == ' ')
			x++;
		i++;
	}
	if (x == i)
		return (0);
	return (1);
}

void	open_history(t_lst *lst)
{
	int	fd;

	if (lst->buffer[0] && valid(lst))
	{
		fd = open(lst->path, O_RDWR | O_APPEND | O_CREAT, 0644);
		write(fd, &lst->buffer, ft_strlen(lst->buffer));
		write(fd, "\n", 1);
		close(fd);
	}
}
