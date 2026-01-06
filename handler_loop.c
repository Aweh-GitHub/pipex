/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:10:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/06 17:54:05 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

pid_t	loop_to_exec_cmds(t_program_info info, int is_here_doc, int fd_f[2], int fd_p[2])
{
	int		fd_cmd[2];
	int		i;
	pid_t	last_pid;


	fd_cmd[FD_IN] = fd_f[FD_IN];
	i = ARG_INDEX_FIRST_CMD;
	if (is_here_doc)
		i += ARG_INDEX_HEREDOC_OFFSET;
	while (i < info.argc - 1)
	{
		if (pipe(fd_p) == -1)
			return (perror("pipe"), -1);
		if (i == info.argc - 2)
			fd_cmd[FD_OUT] = fd_f[FD_OUT];
		else
			fd_cmd[FD_OUT] = fd_p[1];
		last_pid = exec_cmd(t_cmd__new(info.argv[i], info, fd_cmd));
		close(fd_p[1]);
		if (fd_cmd[FD_IN] != fd_f[FD_IN])
			close(fd_cmd[FD_IN]);
		fd_cmd[FD_IN] = fd_p[0];
		i++;
	}
	if (fd_cmd[FD_IN] != fd_f[FD_IN])
		close(fd_cmd[FD_IN]);
	return (last_pid);
}
