/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:43:27 by fbonhomm          #+#    #+#             */
/*   Updated: 2014/12/01 17:43:50 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c + 'A' - 'a');
	return (c);
}
