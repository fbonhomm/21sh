/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auto_compl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:13:39 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 17:59:14 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int					str_in_str(char *s1, char *s2)
{
	size_t			len;
	int				i[2];

	if ((!s1) || (!s2))
		return (0);
	if ((len = ft_strlen(s2)) > (ft_strlen(s2)))
		return (0);
	i[0] = 0;
	i[1] = 0;
	while (s1[i[0]])
	{
		if (s1[i[0]] == s2[i[1]])
			i[1]++;
		i[0]++;
	}
	if (len == (size_t)i[1])
		return (1);
	return (0);
}

void				ft_search_git(t_stc *stc)
{
	DIR				*rep;
	struct dirent	*fichier;

	if (!(rep = opendir(stc->pwd)))
		return ;
	stc->git = 0;
	while ((fichier = readdir(rep)))
	{
		if ((ft_strcmp(fichier->d_name, ".git")) == 0)
		{
			stc->path_git = ft_free(stc->path_git);
			stc->path_git = getcwd(NULL, 1024);
			stc->git = 1;
		}
	}
	if ((stc->git == 0) && (str_in_str(stc->pwd, stc->path_git)))
		stc->git = 1;
	closedir(rep);
}
