/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:54:06 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 18:16:29 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char	*change_pwd(t_stc *stc, char *str, int i)
{
	int	j;
	int	x;

	x = 0;
	j = 0;
	str = ft_free(str);
	str = (char*)malloc(sizeof(char) * (ft_strlen(stc->env[i])));
	while (stc->env[i][j] != '=')
		j++;
	j++;
	while (stc->env[i][j])
		str[x++] = stc->env[i][j++];
	str[x] = '\0';
	return (str);
}

void	ft_set_null(t_stc *stc)
{
	stc->old_pwd = NULL;
	stc->pwd = NULL;
	stc->name = NULL;
	stc->command = NULL;
	stc->path = NULL;
	stc->home = NULL;
	stc->tmp = NULL;
	stc->buf = NULL;
	stc->git = 0;
	stc->path_git = NULL;
	stc->env = NULL;
	stc->str_path = NULL;
	stc->env_tmp = NULL;
	stc->redir = NULL;
	stc->index = 0;
	stc->ctrl_c = 0;
}
