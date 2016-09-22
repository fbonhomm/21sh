/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:31:56 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/03 13:46:53 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_color(char *color, char *text_back, char *text,
				char *text_suite)
{
	ft_putstr("\033[");
	ft_putstr(color);
	ft_putstr("m");
	ft_putstr(text_back);
	ft_putstr(text);
	ft_putstr(text_suite);
	ft_putstr("\033[0m");
}
