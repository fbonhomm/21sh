/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:01:46 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/04/25 18:01:55 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		suite_loop_redir(t_stc *stc, int *i, int *a, int *b)
{
	int		booleen;
	char	car;

	condition_loop(stc, a, b);
	booleen = 0;
	while (stc->pipe[stc->index][(*i)])
	{
		if (((stc->pipe[stc->index][(*i)] == '\"' && booleen == 0) ||
				(stc->pipe[stc->index][(*i)] == '\"' && booleen == 0)) &&
					(car = stc->pipe[stc->index][(*i)]))
			booleen = 1;
		else if ((booleen == 1 && stc->pipe[stc->index][(*i)] == car))
			booleen = 0;
		else if (((stc->pipe[stc->index][(*i)] == '<') ||
			(stc->pipe[stc->index][(*i)] == ' ') ||
				(stc->pipe[stc->index][(*i)] == '>')) && booleen == 0)
			break ;
		else if ((stc->redir[*a][*b] = stc->pipe[stc->index][(*i)]))
			*b = *b + 1;
		(*i) = (*i) + 1;
	}
	condition_loop(stc, a, b);
	if (stc->pipe[stc->index][(*i)] && stc->pipe[stc->index][(*i)] == ' ')
		(*i) = (*i) + 1;
}

void		condition_redir(t_stc *stc, int *i, int *a, int *b)
{
	if (((stc->pipe[stc->index][(*i)] == '0') ||
(stc->pipe[stc->index][(*i)] == '1') || (stc->pipe[stc->index][(*i)] == '2')) &&
		((stc->pipe[stc->index][(*i) + 1] == '>') ||
			(stc->pipe[stc->index][(*i) + 1] == '<')))
	{
		stc->redir[*a][*b] = stc->pipe[stc->index][(*i)];
		*b = *b + 1;
		(*i) = (*i) + 1;
	}
	while ((stc->pipe[stc->index][(*i)] && stc->pipe[stc->index][(*i)] == '<')
	|| (stc->pipe[stc->index][(*i)] && stc->pipe[stc->index][(*i)] == '>'))
	{
		stc->redir[*a][*b] = stc->pipe[stc->index][(*i)];
		*b = *b + 1;
		(*i) = (*i) + 1;
	}
}

void		loop_redir(t_stc *stc, int index, int i)
{
	int		a;
	int		b;
	int		tmp;

	a = 0;
	b = 0;
	tmp = stc->index;
	stc->index = index;
	while (stc->pipe[index][i])
	{
		condition_redir(stc, &i, &a, &b);
		if (((stc->pipe[index][i - 1] == '>') ||
(stc->pipe[index][i - 1] == '<')) && stc->pipe[index][i] == '&' &&
((stc->pipe[index][i + 1] == '-') || (stc->pipe[index][i + 1] == '0') ||
(stc->pipe[index][i + 1] == '1') || (stc->pipe[index][i + 1] == '2')))
		{
			stc->redir[a][b++] = stc->pipe[index][i++];
			stc->redir[a][b++] = stc->pipe[index][i++];
		}
		suite_loop_redir(stc, &i, &a, &b);
	}
	stc->redir[a] = NULL;
	stc->index = tmp;
}

int			loop_back_redir(t_stc *stc, int index, int i)
{
	char	car;
	int		booleen;

	booleen = 0;
	while (stc->pipe[index][i])
	{
		if ((stc->pipe[index][i] == '\"' && booleen == 0) ||
				(stc->pipe[index][i] == '\"' && booleen == 0))
		{
			car = stc->pipe[index][i];
			booleen = 1;
		}
		else if ((booleen == 1 && stc->pipe[index][i] == car))
			booleen = 0;
		else if (((stc->pipe[index][i] == '<') ||
				(stc->pipe[index][i] == '>')) && booleen == 0)
			break ;
		i++;
	}
	return (i);
}

void		split_redir(t_stc *stc, int index)
{
	int		i;
	char	*tmp;

	i = 0;
	ft_count_tab(stc, i);
	stc->command = ft_free_array(stc->command);
	i = loop_back_redir(stc, index, i);
	if ((stc->pipe[index][i - 1] == '0') || (stc->pipe[index][i - 1] == '1') ||
			(stc->pipe[index][i - 1] == '2'))
		i--;
	tmp = strndup(stc->pipe[index], i);
	stc->command = ft_split_quote(tmp);
	tmp = ft_free(tmp);
	loop_redir(stc, index, i);
}
