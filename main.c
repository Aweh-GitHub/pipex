/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:39:24 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/10 12:58:30 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>


int	_wait_exit_code(pid_t last_pid)
{
	pid_t	pid;
	int		exit_code;
	int		status;

	exit_code = 0;
	while (TRUE)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (pid == last_pid)
		{
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				exit_code = 128 + WTERMSIG(status);
		}
	}
	return (exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	t_program_info	info;
	int				exit_code;
	pid_t			last_pid;
	int				fd_init_status;

	if (argc <= 4)
		return (ft_printf(ERR_ARGS_DEFAULT), EXIT_FAILURE);
	info = t_program_args_info__new(argc, argv, envp);
	fd_init_status = handle_fd_init_mode(&info);
	if (fd_init_status == -1)
		return (close_fds(info.fd_f), EXIT_FAILURE);
	last_pid = handler_loop(&info, fd_init_status);
	close_fds(info.fd_f);
	exit_code = _wait_exit_code(last_pid);
	return (exit_code);
}
