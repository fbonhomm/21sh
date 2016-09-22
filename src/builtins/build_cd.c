/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 21:20:45 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 18:11:42 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		ft_message_err(char *str, int i)
{
	if (i == 1)
		ft_print_str_endl(3, "cd: no such file or directory: ", str, "\n");
	else if (i == 2)
		ft_print_str_endl(3, "cd: permission denied: ", str, "\n");
	else if (i == 3)
		ft_print_str_endl(1, "cd: too many arguments\n");
	else if (i == 4)
		ft_print_str_endl(1, "/usr/bin/cd: line 4: cd: HOME not set\n");
	else
		ft_print_str_endl(3, "cd: not directory: ", str, "\n");
}

int			ft_access(char *str)
{
	if (access(str, F_OK) == -1)
		return (1);
	if (access(str, X_OK) == -1)
	{
		opendir(str);
		if (errno == ENOTDIR)
			return (4);
		return (2);
	}
	return (0);
}

void		ft_chdir(char *str, t_stc *stc)
{
	int		ret;
	char	*tmp;

	tmp = NULL;
	if ((chdir(str)) != 0)
	{
		if ((ret = ft_access(str)) != 0)
			ft_message_err(str, ret);
		else
			ft_message_err(str, 0);
		return ;
	}
	stc->old_pwd = ft_free(stc->old_pwd);
	stc->old_pwd = ft_strdup(stc->pwd);
	stc->pwd = ft_free(stc->pwd);
	tmp = getcwd(NULL, 1024);
	stc->pwd = ft_strdup(tmp);
	tmp = ft_free(tmp);
	tmp = ft_strjoin("PWD=", stc->pwd);
	build_setenv(stc, tmp);
	tmp = ft_free(tmp);
	tmp = ft_strjoin("OLDPWD=", stc->old_pwd);
	build_setenv(stc, tmp);
	tmp = ft_free(tmp);
}

void		build_cd(t_stc *stc)
{
	if (stc->command[1] == NULL)
	{
		if (stc->home)
			ft_chdir(stc->home, stc);
		else
			ft_message_err(NULL, 4);
	}
	else if (stc->command[2] != NULL)
		ft_message_err(NULL, 3);
	else if ((ft_strcmp(stc->command[1], "-")) == 0 &&
		(stc->command[2] == NULL))
	{
		if (stc->old_pwd)
			ft_chdir(stc->old_pwd, stc);
	}
	else
		ft_chdir(stc->command[1], stc);
}
