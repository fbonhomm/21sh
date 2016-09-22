/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 15:07:50 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 19:24:38 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			search_egal_env(char *str)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i++] == '=')
			x++;
	}
	i = 0;
	if (x > 0)
	{
		while (str[i] != '=')
		{
			if ((!(ft_isalnum(str[i]))) && (str[i] != '_'))
				return (2);
			i++;
		}
		return (1);
	}
	return (0);
}

char		**in_env_exe(t_stc *stc, int *x)
{
	char	**tmp;

	while (stc->command[*x])
		*x = *x + 1;
	tmp = ft_strdup_array(stc->command);
	stc->command = ft_free_array(stc->command);
	stc->command = (char**)malloc(sizeof(char*) * ((*x) + 2));
	*x = 0;
	env_to_stc(stc);
	return (tmp);
}

void		env_exe(t_stc *stc, char **tmp, int i, int x)
{
	pid_t	pid;
	int		ret;

	while (stc->command[i] && (ret = search_egal_env(stc->command[i])) == 1)
		build_setenv(stc, stc->command[i++]);
	if (ret != 2)
	{
		if (stc->command[i] && (x = i))
		{
			tmp = in_env_exe(stc, &x);
			while (tmp[i])
				stc->command[x++] = ft_strdup(tmp[i++]);
			stc->command[x] = NULL;
			tmp = ft_free_array(tmp);
			if ((pid = fork()) == 0)
			{
				if (!ft_builtin(stc))
					execve_binary(stc);
				exit(0);
			}
			wait(NULL);
		}
		else
			ft_put_array(stc->env, "\n");
	}
}

void		build_env(t_stc *stc)
{
	int		i;
	char	**tmp;

	tmp = NULL;
	if ((!stc->command[1]))
		ft_put_array(stc->env, "\n");
	else
	{
		i = 1;
		stc->env_tmp = ft_strdup_array(stc->env);
		if (((ft_strcmp(stc->command[1], "-i") == 0) && (i = 2)) ||
				((ft_strcmp(stc->command[1], "-") == 0) && (i = 2)))
			stc->env = ft_free_array(stc->env);
		if (stc->command[i])
			env_exe(stc, tmp, i, 0);
		stc->env = ft_free_array(stc->env);
		stc->env = ft_strdup_array(stc->env_tmp);
		env_to_stc(stc);
		stc->env_tmp = ft_free_array(stc->env_tmp);
	}
}
