/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 15:09:53 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 19:31:30 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		delete_var_env(t_stc *stc, size_t index)
{
	char	**tmp;
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	tmp = (char**)malloc(sizeof(char*) * (ft_strlen_second_dim(stc->env) + 1));
	while (stc->env[i])
	{
		if (i == index)
			i++;
		else
			tmp[j++] = ft_strdup(stc->env[i++]);
	}
	tmp[j] = NULL;
	stc->env = ft_free_array(stc->env);
	stc->env = ft_strdup_array(tmp);
	tmp = ft_free_array(tmp);
}

void		build_unsetenv(t_stc *stc)
{
	int		i;
	int		x;
	size_t	j;

	x = 1;
	while (stc->command[x])
	{
		i = 0;
		while (stc->env[i])
		{
			j = 0;
			while (stc->env[i][j] != '=')
				j++;
			if ((ft_strncmp(stc->env[i], stc->command[x], j) == 0) &&
				(j == (ft_strlen(stc->command[x]))))
			{
				delete_var_env(stc, i);
				break ;
			}
			i++;
		}
		x++;
	}
}
