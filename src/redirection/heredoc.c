/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char		*loop_loop_heredoc(t_lst *lst, t_stc *stc)
{
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
			return (NULL);
		insert(lst, stc, buf);
	}
	ft_putchar('\n');
	lst->buffer[ft_strlen(lst->buffer)] = '\n';
	return (ft_strdup(lst->buffer));
}

void		loop_heredoc(t_stc *stc, t_lst *lst, char **tmp, char *key)
{
	char	*tmp1;

	tmp1 = NULL;
	stc->tmp = ft_free(stc->tmp);
	if ((stc->tmp = loop_loop_heredoc(lst, stc)) == NULL &&
		(stc->ctrl_c == 1))
	{
		*tmp = ft_free(*tmp);
		key = ft_free(key);
		stc->tmp = ft_free(stc->tmp);
		return ;
	}
	if (ft_strcmp(stc->tmp, key) == 0)
		return ;
	if (tmp)
		tmp1 = ft_strjoin(*tmp, stc->tmp);
	else
		tmp1 = ft_strdup(stc->tmp);
	*tmp = ft_free(*tmp);
	*tmp = ft_strdup(tmp1);
	tmp1 = ft_free(tmp1);
}

char		*loop_init_heredoc(t_stc *stc, int *j, t_lst *lst)
{
	char	*tmp;
	char	*key;
	int		i;

	tmp = NULL;
	stc->tmp = ft_free(stc->tmp);
	i = *j;
	while (stc->redir[i] && ft_valid(stc, i) != 1 && ft_valid(stc, i) != 2)
	{
		if (ft_strcmp(stc->redir[i], "<<") == 0)
		{
			*j = i + 1;
			tmp = ft_free(tmp);
			key = ft_strjoin(stc->redir[i + 1], "\n");
			while (ft_strcmp(stc->tmp, key) != 0)
			{
				loop_heredoc(stc, lst, &tmp, key);
				if (stc->ctrl_c == 1)
					return (NULL);
			}
			key = ft_free(key);
		}
		i++;
	}
	return (tmp);
}

int			heredoc(t_stc *stc, int *j, t_lst *lst)
{
	pid_t	pid;
	char	*text;
	int		fd_tab[2];

	init_termios();
	tputs(tgetstr("im", &(lst->p)), 0, ft_outc);
	if ((text = loop_init_heredoc(stc, j, lst)) == NULL)
		return (0);
	pipe(fd_tab);
	if ((pid = fork()) == 0)
	{
		dup2(fd_tab[1], STDOUT_FILENO);
		close(fd_tab[0]);
		ft_putstr_fd(text, fd_tab[1]);
		exit(0);
	}
	wait(NULL);
	dup2(fd_tab[0], STDIN_FILENO);
	close(fd_tab[1]);
	tputs(tgetstr("ei", &(lst->p)), 0, ft_outc);
	return (1);
}
