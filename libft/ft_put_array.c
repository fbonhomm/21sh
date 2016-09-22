/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 14:04:41 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/10/12 14:04:54 by fbonhomm         ###   ########.fr       */
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
