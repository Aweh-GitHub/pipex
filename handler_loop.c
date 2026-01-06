/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:10:46 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/06 14:47:20 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

static int	_init_fdfiles(int *fd_files, int is_heredoc, int argc, char **argv)
{
	char	*fileout;

	fileout = argv[argc - 1];
	if (is_heredoc)
		fd_files[FD_IN] = handle_here_doc(argv[ARG_INDEX_HEREDOC_EOF]);
	else
	{
		fd_files[FD_IN] = open(argv[ARG_INDEX_FILEIN], O_RDONLY);
		if (fd_files[FD_IN] == -1)
			perror(argv[ARG_INDEX_FILEIN]);
	}
	if (is_heredoc)
		fd_files[FD_OUT] = open(fileout, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd_files[FD_OUT] = open(fileout, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_files[FD_OUT] == -1)
		return (perror(fileout), FALSE);
	return (TRUE);
}

static void	_verify_args(int is_heredoc, int argc)
{
	if (!is_heredoc && argc < REQUIRED_ARGC_DEFAULT)
	{
		ft_printf(ERR_ARGS_DEFAULT);
		exit(EXIT_FAILURE);
	}
	else if (is_heredoc && argc < REQUIRED_ARGC_HEREDOC)
	{
		ft_printf(ERR_ARGS_HEREDOC);
		exit(EXIT_FAILURE);
	}
}

pid_t	loop_to_exec_cmds(t_program_info info, int fd_f[2], int fd_p[2])
{
	int		is_heredoc;
	int		fd_cmd[2];
	int		i;
	pid_t	last_pid;

	is_heredoc = ft_strcmp(info.argv[ARG_INDEX_HEREDOC], HEREDOC) == 0;
	_verify_args(is_heredoc, info.argc);
	if (_init_fdfiles(fd_f, is_heredoc, info.argc, info.argv) == FALSE)
		return (-1);
	fd_cmd[FD_IN] = fd_f[FD_IN];
	i = ARG_INDEX_FIRST_CMD;
	if (is_heredoc)
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
