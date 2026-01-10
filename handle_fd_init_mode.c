/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fd_init_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:55:05 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/10 15:47:22 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

static int	_init_fdfiles(t_program_info *info, int is_here_doc)
{
	char	*out;

	out = info->argv[info->argc - 1];
	if (is_here_doc)
		info->fd_f[FD_IN] = handle_here_doc(info->argv[ARG_INDEX_HEREDOC_EOF]);
	else
	{
		info->fd_f[FD_IN] = open(info->argv[ARG_INDEX_FILEIN], O_RDONLY);
		if (info->fd_f[FD_IN] == -1)
			perror(info->argv[ARG_INDEX_FILEIN]);
	}
	if (is_here_doc)
		info->fd_f[FD_OUT] = open(out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		info->fd_f[FD_OUT] = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->fd_f[FD_OUT] == -1)
		return (perror(out), FALSE);
	return (TRUE);
}

int	handle_fd_init_mode(t_program_info *info)
{
	int		here_doc_mode;

	here_doc_mode = ft_strcmp(info->argv[ARG_INDEX_HEREDOC], HEREDOC) == 0;
	if (_init_fdfiles(info, here_doc_mode) == FALSE)
		return (-1);
	return (here_doc_mode);
}
