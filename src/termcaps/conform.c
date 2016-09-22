/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 11:47:15 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/10/06 11:58:15 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			conform(char *buf)
{
	if ((LEFT) || (RIGHT) || (UP) || (DOWN) || (TAB) || (ENTER) || (CTRLD) ||
		(CTRLL) || (CTRLE) || (CTRLW) || (CTRLP) || (CTRLU) ||
			(CTRLI) || (CTRLR) || (DEL) || (HOME) || (END))
		return (1);
	if ((buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59 &&
buf[4] == 50 && buf[5] == 65 && buf[6] == 0) || (buf[0] == 27 && buf[1] == 91 &&
buf[2] == 49 && buf[3] == 59 && buf[4] == 50 && buf[5] == 66 && buf[6] == 0))
		return (1);
	if ((buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59 &&
buf[4] == 50 && buf[5] == 67 && buf[6] == 0) || ((buf[0] == 27 &&
buf[1] == 91 && buf[2] == 54 && buf[3] == 126 && buf[4] == 0)))
		return (1);
	if (ft_isprint(buf[0]) && (!buf[1]))
		return (1);
	return (0);
}
