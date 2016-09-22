/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:46:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/06/28 15:46:32 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		fusion_fd(char *str)
{
	if ((ft_strcmp(str, "2>&1") == 0) || (ft_strcmp(str, "1<&2") == 0))
		dup2(STDOUT_FILENO, STDERR_FILENO);
	else if ((ft_strcmp(str, "1>&2") == 0) || (ft_strcmp(str, "2<&1") == 0))
		dup2(STDERR_FILENO, STDOUT_FILENO);
	else if ((ft_strcmp(str, "1>&0") == 0) || (ft_strcmp(str, "0<&1") == 0))
		dup2(STDIN_FILENO, STDOUT_FILENO);
	else if ((ft_strcmp(str, "0>&1") == 0) || (ft_strcmp(str, "1<&0") == 0))
		dup2(STDOUT_FILENO, STDIN_FILENO);
	else if ((ft_strcmp(str, "2>&0") == 0) || (ft_strcmp(str, "0<&2") == 0))
		dup2(STDIN_FILENO, STDERR_FILENO);
	else if ((ft_strcmp(str, "0>&2") == 0) || (ft_strcmp(str, "2<&0") == 0))
		dup2(STDERR_FILENO, STDIN_FILENO);
	else if ((ft_strcmp(str, "0>&-") == 0) || (ft_strcmp(str, "0<&-") == 0))
		close(STDIN_FILENO);
	else if ((ft_strcmp(str, "1>&-") == 0) || (ft_strcmp(str, "1<&-") == 0))
		close(STDOUT_FILENO);
	else if ((ft_strcmp(str, "2>&-") == 0) || (ft_strcmp(str, "2<&-") == 0))
		close(STDERR_FILENO);
	else
		return (-1);
	return (1);
}
