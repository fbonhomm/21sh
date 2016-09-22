/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 15:36:59 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/18 18:36:46 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void				prompt_color(t_lst *lst, t_stc *stc)
{
	ft_search_git(stc);
	ft_putstr_color("44;1", " ", stc->name, " ");
	ft_putstr_color("30;43", " ->", stc->pwd, " ");
	if (stc->git == 1)
	{
		ft_putstr_color("0;37;46", NULL, " + git ", NULL);
		lst->pos_y = ft_strlen(stc->name) + ft_strlen(stc->pwd) + 16;
	}
	else
		lst->pos_y = ft_strlen(stc->name) + ft_strlen(stc->pwd) + 9;
	ft_putstr_color("31", NULL, " * ", NULL);
}

void				prompt_nocolor(t_lst *lst)
{
	ft_putstr(" ?> ");
	lst->pos_y = 4;
}

void				prompt(t_stc *stc, t_lst *lst, int i)
{
	static int		prompt;

	if ((stc && i != 2) && ((prompt == 0) || (prompt == 1 && i == 1)))
	{
		prompt = i;
		if (lst->index_color == 0)
			prompt_color(lst, stc);
		if (lst->index_color == 1)
			prompt_nocolor(lst);
		lst->pos_x = 0;
		lst->index = 0;
	}
	else
		prompt = 0;
}

void				welcome(void)
{
	ft_putstr("\n\t\t\033[36m-----------------------------------\033[0m\n");
	ft_putstr("\t\t\033[36m  Welcome in my shell [fbonhomm]\033[0m    \n");
	ft_putstr("\t\t\033[36m-----------------------------------\033[0m\n\n");
}
