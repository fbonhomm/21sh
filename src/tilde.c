/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 23:20:49 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 19:28:18 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		loop_tilde(t_stc *stc, char ***tabl, int i)
{
	char	*tmp;
	int		x;
	int		j;

	x = 1;
	j = ft_strlen(stc->home);
	tmp = ft_strdup((*tabl)[i]);
	(*tabl)[i] = ft_free((*tabl)[i]);
	(*tabl)[i] = ft_strdup(stc->home);
	while (tmp[x])
		(*tabl)[i][j++] = tmp[x++];
	(*tabl)[i][j] = '\0';
	tmp = ft_free(tmp);
}

void		tilde(t_stc *stc, char ***tabl)
{
	int		i;

	i = 0;
	if (stc->home)
	{
		while ((*tabl)[i])
		{
			if (ft_strcmp(((*tabl))[i], "~") == 0)
			{
				(*tabl)[i] = ft_free((*tabl)[i]);
				(*tabl)[i] = ft_strdup(stc->home);
			}
			if ((ft_strncmp((*tabl)[i], "~/", 2) == 0))
				loop_tilde(stc, tabl, i);
			i++;
		}
	}
}
