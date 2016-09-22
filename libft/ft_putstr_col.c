/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:31:56 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 17:45:18 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define YELLOW "\e[30;43m"
#define RESET "\e[0m"

void		ft_putstr_col(char const *s)
{
	int i;

	i = 0;
	ft_putstr(YELLOW);
	ft_putstr(" ->");
	while (s && s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar(' ');
	ft_putstr(RESET);
}
