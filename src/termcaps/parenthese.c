/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthese.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		loop_match(char *ponct, int i)
{
	int		j;
	char	tmp[1024];

	ft_bzero(tmp, 1024);
	ft_strncpy(tmp, ponct, i);
	j = i + 1;
	while (ponct[j])
		tmp[i++] = ponct[j++];
	ft_bzero(ponct, 1024);
	ft_strcpy(ponct, tmp);
}

int			search_ponct(char *ponct, char car)
{
	int		i;

	i = 0;
	while (ponct[i])
	{
		if (ponct[i] == car)
			return (i);
		if (ponct[i] == 40 && car == 41)
			return (i);
		if (ponct[i] == 91 && car == 93)
			return (i);
		if (ponct[i] == 123 && car == 125)
			return (i);
		i++;
	}
	return (-1);
}

void		match(t_lst *lst, char *ponct, int *count)
{
	int		i;

	if (((lst->buffer[*count] == ')') || (lst->buffer[*count] == '}') ||
			(lst->buffer[*count] == ']')) &&
				((i = search_ponct(ponct, lst->buffer[*count])) >= 0))
		loop_match(ponct, i);
	else if (((lst->buffer[*count] == '"') || (lst->buffer[*count] == '\'') ||
			(lst->buffer[*count] == '`')) &&
				((i = search_ponct(ponct, lst->buffer[*count])) >= 0))
		loop_match(ponct, i);
	else if ((lst->buffer[*count] == '(' || lst->buffer[*count] == '{' ||
		lst->buffer[*count] == '[' || lst->buffer[*count] == '"' ||
			lst->buffer[*count] == '\'' || lst->buffer[*count] == '`') &&
				(ft_strlen(ponct)) < 1024 - 1)
		ponct[ft_strlen(ponct)] = lst->buffer[*count];
	*count = *count + 1;
}

int			loop_parenthese(t_lst *lst, t_stc *stc, char *ponct)
{
	int		i;
	char	buf[10];

	ft_putstr("> ");
	ft_bzero(lst->buffer, MAX);
	lst->pos_x = 0;
	lst->pos_y = 2;
	lst->index = 0;
	while (!(ENTER))
	{
		init_termios();
		ft_bzero(buf, 10);
		read(STDIN_FILENO, buf, 10);
		if (stc->ctrl_c == 1)
			return (0);
		insert(lst, stc, buf);
	}
	ft_bzero(buf, 10);
	while (lst->buffer[lst->index + 1])
		get_cursor(MVRIGHT, lst);
	ft_putchar('\n');
	i = 0;
	while (lst->buffer[i])
		match(lst, ponct, &i);
	return (1);
}

int			parenthese(t_lst *lst, t_stc *stc)
{
	int		i;
	char	ponct[1024];
	char	*tmp;

	i = 0;
	tmp = NULL;
	ft_bzero(ponct, 1024);
	while (lst->buffer[i])
		match(lst, ponct, &i);
	if (ponct[0])
	{
		while ((ponct[0]) && (ft_strlen(stc->buf) <= MAX_PARENT))
		{
			if ((loop_parenthese(lst, stc, ponct)) == 0)
				return (0);
			if (lst->buffer[0])
			{
				tmp = ft_strdup(stc->buf);
				stc->buf = ft_free(stc->buf);
				stc->buf = ft_strjoin(tmp, lst->buffer);
				tmp = ft_free(tmp);
			}
		}
	}
	return (1);
}
