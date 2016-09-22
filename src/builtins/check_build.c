/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 23:23:12 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 18:12:55 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		ft_option_1(t_stc *stc)
{
	if (((ft_strcmp(stc->command[0], "exit")) == 0) && (!stc->command[1]))
		end(stc, 0);
	else if (((ft_strcmp(stc->command[0], "exit")) == 0) &&
			(stc->command[1]) && (!stc->command[2]))
		end(stc, atoi(stc->command[1]));
	else
		ft_print_str_endl(1, "exit: too many arguments\n");
	return (1);
}

int		ft_option_2(t_stc *stc)
{
	build_cd(stc);
	return (1);
}

int		ft_option_3(t_stc *stc)
{
	if (!stc->command[1])
		ft_put_array(stc->env, "\n");
	else if (stc->command[2])
		ft_print_str_endl(1, "setenv: Too many arguments\n");
	else
	{
		if ((search_egal(stc->command[1], 0)) == 0)
			return (1);
		else
			build_setenv(stc, stc->command[1]);
	}
	return (1);
}

int		ft_option_4(t_stc *stc)
{
	if (!stc->command[1])
		ft_print_str_endl(1, "too few argument\n");
	else
		build_unsetenv(stc);
	return (1);
}

int		ft_option_5(t_stc *stc)
{
	if (stc->env)
		build_env(stc);
	return (1);
}
