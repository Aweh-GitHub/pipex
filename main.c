/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:39:24 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/07 10:33:04 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

static int	_wait_exit_code(pid_t last_pid)
{
	pid_t	pid;
	int		state;
	int		exit_code;

	if (last_pid == -1)
		return (EXIT_FAILURE);
	exit_code = 0;
	pid = wait(&state);
	while (pid > 0)
	{
		if (pid == last_pid && WIFEXITED(state))
			exit_code = WEXITSTATUS(state);
	}
	return (exit_code);
}

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

int	handle_heredoc(t_program_info info, int fd_f[2])
{
	int		is_heredoc;

	is_heredoc = ft_strcmp(info.argv[ARG_INDEX_HEREDOC], HEREDOC) == 0;
	if (_init_fdfiles(fd_f, is_heredoc, info.argc, info.argv) == FALSE)
		return (is_heredoc);
	return (is_heredoc);
}

int	main(int argc, char **argv, char **envp)
{
	t_program_info	info;
	int				fd_f[2];
	int				fd_p[2];
	int				exit_code;

	if (argc <= 4)
		return (ft_printf(ERR_ARGS_DEFAULT), EXIT_FAILURE);
	info = t_program_args_info__new(argc, argv, envp);
	exit_code = _wait_exit_code(loop_to_exec_cmds(info, handle_heredoc(info, fd_f), fd_f, fd_p));
	close_fds(fd_f);
	return (exit_code);
}
