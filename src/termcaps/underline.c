/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		cut(t_lst *lst, char *buf, char *tmp, int i)
{
	ft_bzero(lst->clipboard, MAX);
	ft_strcpy(lst->clipboard, tmp);
	ft_bzero(buf, 10);
	buf[0] = 127;
	while (lst->index > i)
		del(lst, buf);
}

void		copy(t_lst *lst, char *tmp)
{
	ft_bzero(lst->clipboard, MAX);
	ft_strcpy(lst->clipboard, tmp);
}

void		reset_display(t_lst *lst, int i)
{
	int		tmp;

	tmp = lst->index;
	while (lst->index > i)
		get_cursor(MVLEFT, lst);
	while (lst->index <= tmp && lst->buffer[lst->index])
	{
		tputs(tgetstr("dc", &(lst->p)), 0, ft_outc);
		ft_putchar(lst->buffer[lst->index]);
		tputs(tgetstr("le", &(lst->p)), 0, ft_outc);
		get_cursor(MVRIGHT, lst);
	}
}

void		cast_clipboard(t_lst *lst, int *count, char *buf, char *tmp)
{
	if (lst->buffer[lst->index])
	{
		tputs(tgetstr("dc", &(lst->p)), 0, ft_outc);
		ft_putchar(lst->buffer[lst->index]);
		tmp[*count] = lst->buffer[lst->index];
		tputs(tgetstr("le", &(lst->p)), 0, ft_outc);
		get_cursor(MVRIGHT, lst);
		*count = *count + 1;
	}
	ft_bzero(buf, 10);
	read(STDIN_FILENO, buf, 10);
}

int			underline(t_lst *lst, char *tmp1)
{
	char	buf[10];
	char	tmp[MAX];
	int		count;
	int		i;

	count = 0;
	i = lst->index;
	ft_bzero(buf, 10);
	ft_bzero(tmp, MAX);
	ft_strcpy(buf, tmp1);
	if (lst->buffer[lst->index])
	{
		tputs(tgetstr("so", &(lst->p)), 0, ft_outc);
		while (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 &&
				buf[3] == 59 && buf[4] == 50 && buf[5] == 67 && buf[6] == 0)
			cast_clipboard(lst, &count, buf, tmp);
		tputs(tgetstr("se", &(lst->p)), 0, ft_outc);
		if (CTRLU)
			cut(lst, buf, tmp, i);
		if (CTRLI)
			copy(lst, tmp);
		if (!(CTRLU))
			reset_display(lst, i);
	}
	return (1);
}
