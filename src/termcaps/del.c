/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			del(t_lst *lst, char *buf)
{
	char	tmp[MAX];
	int		i;
	int		c;

	i = lst->index - 1;
	ft_bzero(tmp, MAX);
	if (lst->buffer[0] && lst->index)
	{
		ft_strncpy(tmp, lst->buffer, i);
		c = i + 1;
		while (lst->buffer[c])
			tmp[i++] = lst->buffer[c++];
		ft_bzero(lst->buffer, MAX);
		ft_strcpy(lst->buffer, tmp);
		get_cursor(MVLEFT, lst);
		tputs(tgetstr("dc", &(lst->p)), 0, ft_outc);
		print_line(lst, buf);
	}
	return (1);
}
