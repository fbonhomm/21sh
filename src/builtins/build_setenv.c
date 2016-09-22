/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 15:07:50 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/18 18:24:17 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			err_env2(int ret)
{
	ft_putstr_fd("setenv: Variable name must begin with a letter\n", 2);
	return (ret);
}

int			search_egal(char *str, int i)
{
	int		x;
	int		booleen;

	x = 0;
	booleen = 0;
	if ((!(ft_isalpha(str[0]))) && (str[0] != '_'))
		return (err_env2(0));
	while (str[i])
	{
		if (str[i] == '=' && (booleen = 1))
			x++;
		if ((!(ft_isalnum(str[i]))) && (str[i] != '_') && (!booleen))
		{
			ft_putstr_fd("setenv: Variable name must begin with a letter\n", 2);
			return (0);
		}
		i++;
	}
	if (x == 0)
	{
		ft_putstr_fd("Usage: [Variable=Valeur]\n", 2);
		return (0);
	}
	return (1);
}

void		env_null_setenv(t_stc *stc, char *str)
{
	stc->env = (char**)malloc(sizeof(char*) * 2);
	stc->env[0] = ft_strdup(str);
	stc->env[1] = NULL;
}

void		set_setenv(t_stc *stc, char *str, int j, int p)
{
	char	**tmp;
	int		i;

	i = 0;
	while (str[j] != '=')
		j++;
	tmp = (char**)malloc(sizeof(char*) * (ft_strlen_second_dim(stc->env) + 2));
	while (stc->env[i])
	{
		if ((ft_strncmp(stc->env[i], str, (j + 1)) == 0) && (p = 1))
			tmp[i] = ft_strdup(str);
		else
			tmp[i] = ft_strdup(stc->env[i]);
		i++;
	}
	if (p == 0)
		tmp[i++] = ft_strdup(str);
	tmp[i] = NULL;
	stc->env = ft_free_array(stc->env);
	stc->env = ft_strdup_array(tmp);
	tmp = ft_free_array(tmp);
}

void		build_setenv(t_stc *stc, char *str)
{
	if (!stc->env)
		env_null_setenv(stc, str);
	else
		set_setenv(stc, str, 0, 0);
}
