/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_standard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:14:12 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/11 18:22:54 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		init_standard()
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag = (ICANON | ECHO);
	tcsetattr(0, 0, &term);
}
