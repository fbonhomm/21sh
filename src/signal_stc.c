/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:16:42 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 19:27:18 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_stc				*signal_stc(t_stc *tmp)
{
	static t_stc	*stc;

	if (tmp != NULL)
		stc = tmp;
	return (stc);
}
