/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 15:34:39 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 19:09:30 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		init_stc(char *str, char **var, int x)
{
	int		y;

	y = 0;
	if (str[x])
	{
		*var = (char*)malloc(sizeof(char) * (ft_strlen(str + 1)));
		while (str[x])
			(*var)[y++] = str[x++];
		(*var)[y] = '\0';
	}
}

int			ft_strcmp_env(const char *s1, const char *s2, size_t j)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = j;
	if (s2)
	{
		while ((s1[j] == s2[i]) && (s1[j]) && (s2[i]))
		{
			i++;
			j++;
		}
		if ((i == (ft_strlen(s2))) && (i == (ft_strlen(s1) - ret)))
			return (0);
	}
	return (1);
}

void		change_path(t_stc *stc, int i)
{
	stc->str_path = ft_strdup(stc->env[i]);
	stc->path = ft_split(stc->env[i], ':', '=');
}

void		env_null(t_stc *stc)
{
	stc->str_path = ft_free(stc->str_path);
	stc->path = ft_free_array(stc->path);
	stc->name = ft_free(stc->name);
	stc->home = ft_free(stc->home);
}

void		env_to_stc(t_stc *stc)
{
	int		i;

	i = 0;
	env_null(stc);
	while (stc->env && stc->env[i])
	{
		if ((ft_strncmp(stc->env[i], "LOGNAME=", 8) == 0) &&
				(ft_strcmp_env(stc->env[i], stc->name, 8) != 0))
			init_stc(stc->env[i], &stc->name, 8);
		else if ((ft_strncmp(stc->env[i], "HOME=", 5) == 0) &&
				(ft_strcmp_env(stc->env[i], stc->home, 5) != 0))
			init_stc(stc->env[i], &stc->home, 5);
		else if (ft_strncmp(stc->env[i], "PATH=", 5) == 0 &&
			(ft_strcmp_env(stc->env[i], stc->str_path, 0) != 0))
			change_path(stc, i);
		else if ((ft_strncmp(stc->env[i], "PWD=", 4)) == 0 &&
			(ft_strcmp_env(stc->env[i], stc->pwd, 4) != 0))
			stc->pwd = change_pwd(stc, stc->pwd, i);
		else if ((ft_strncmp(stc->env[i], "OLDPWD=", 7)) == 0 &&
			(ft_strcmp_env(stc->env[i], stc->old_pwd, 7) != 0))
			stc->old_pwd = change_pwd(stc, stc->old_pwd, i);
		i++;
	}
}
