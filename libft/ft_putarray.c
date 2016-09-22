/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 13:42:58 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/27 13:43:02 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_array(char **tab, char *c)
{
	int	i;

	i = 0;
	if (!tab || !c)
		return ;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putstr(c);
		i++;
	}
}
