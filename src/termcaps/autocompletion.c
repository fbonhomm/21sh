/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int					completion(t_lst *lst, int i, DIR *rep, struct dirent *f)
{
	int				len;
	char			tmp[10];

	ft_bzero(tmp, 10);
	tmp[0] = 127;
	i = 0;
	len = ft_strlen(lst->tmp_compl);
	while (len > 0)
	{
		del(lst, tmp);
		len--;
	}
	tputs(tgetstr("ce", &(lst->p)), 0, ft_outc);
	while (f->d_name[i] && ft_strlen(lst->buffer) < MAX - 1)
	{
		create_line(lst, f->d_name[i]);
		print_line(lst, NULL);
		if (lst->pos_y > (lst->col) && (lst->pos_y = 0))
			lst->pos_x++;
		i++;
	}
	closedir(rep);
	return (1);
}

void				copy_keyword(t_lst *lst)
{
	int				i;
	int				len;

	i = 0;
	ft_bzero(lst->tmp_compl, MAX);
	len = ft_strlen(lst->buffer);
	while (len > 0 && lst->buffer[len] != ' ' && lst->buffer[len] != '/')
		len--;
	if (len != 0)
		len++;
	while (lst->buffer[len])
		lst->tmp_compl[i++] = lst->buffer[len++];
}

void				copy_path(t_lst *lst)
{
	int				i;
	int				len;

	i = 0;
	len = ft_strlen(lst->buffer);
	ft_bzero(lst->path_compl, MAX);
	while (len > 0 && lst->buffer[len] != ' ')
		len--;
	if (len != 0)
		len++;
	while (lst->buffer[len])
		lst->path_compl[i++] = lst->buffer[len++];
	while (len > 0 && lst->buffer[len] != '/' && (len--))
		lst->path_compl[i--] = '\0';
	if (len == 0)
	{
		lst->path_compl[0] = '.';
		lst->path_compl[1] = '/';
		lst->path_compl[2] = '\0';
	}
}

int					autocompletion(t_lst *lst)
{
	int				i;
	int				len;
	DIR				*rep;
	struct dirent	*f;

	copy_path(lst);
	if ((rep = opendir(lst->path_compl)) && lst->buffer[0])
	{
		i = 0;
		copy_keyword(lst);
		len = ft_strlen(lst->tmp_compl);
		while ((f = readdir(rep)))
		{
			if (((ft_strncmp(f->d_name, lst->tmp_compl, len)) == 0) && len > 0)
				return (completion(lst, i, rep, f));
			i++;
		}
		closedir(rep);
	}
	return (0);
}
