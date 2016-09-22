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

void		is_isatty(void)
{
	if ((isatty(STDIN_FILENO) == 0) || (isatty(STDOUT_FILENO) == 0) ||
		(isatty(STDERR_FILENO) == 0))
	{
		ft_putstr("\n\t| file descriptor system no open |\n\n");
		exit(0);
	}
}

void		shvl(t_stc *stc, char *tmp, char *t, int i)
{
	int		j;
	int		h;
	int		ind;
	char	*c;

	j = 0;
	h = 6;
	while (stc->env[i][h])
		t[j++] = stc->env[i][h++];
	t[j] = '\0';
	ind = ft_atoi(t);
	ind++;
	c = ft_itoa(ind);
	j = -1;
	h = 0;
	while (stc->env[i][++j] != '=')
		tmp[j] = stc->env[i][j];
	tmp[j++] = '=';
	while (c[h])
		tmp[j++] = c[h++];
	tmp[j++] = '\0';
	stc->env[i] = ft_free(stc->env[i]);
	c = ft_free(c);
	stc->env[i] = ft_strdup(tmp);
}

void		ft_dupenv(t_stc *stc, char **env)
{
	int		i;
	char	t[10];
	char	tmp[100];

	if (!env || !env[0])
		stc->env = NULL;
	else
		stc->env = ft_strdup_array(env);
	i = 0;
	while (stc->env && stc->env[i])
	{
		if ((ft_strncmp(stc->env[i], "SHLVL=", 6) == 0))
			shvl(stc, tmp, t, i);
		i++;
	}
}

void		init(t_stc *stc, char **env)
{
	is_isatty();
	ft_set_null(stc);
	stc->pwd = getcwd(NULL, 1024);
	ft_dupenv(stc, env);
	env_to_stc(stc);
}
