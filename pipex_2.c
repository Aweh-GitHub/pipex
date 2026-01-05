/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:10:39 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/05 15:41:20 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

static void	_print_error(t_cmd cmd)
{
	ft_putstr_fd(cmd.m_name, STDERR_FILENO);
	if (cmd.m_name && cmd.m_name[0] == '/')
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	else
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
}

int	exec_cmd(t_cmd cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
		return (t_cmd__free(cmd), TRUE);
	if (pid < 0)
		return (t_cmd__free(cmd), perror("fork"), exit(EXIT_FAILURE), ERROR);
	if (cmd.fds[STDIN_FILENO] == -1)
	{
		if (cmd.fds[STDOUT_FILENO] != -1)
			close(cmd.fds[STDOUT_FILENO]);
		exit(EXIT_FAILURE);
	}
	if (dup2(cmd.fds[STDIN_FILENO], STDIN_FILENO) == DUP2_ERROR
		|| dup2(cmd.fds[STDOUT_FILENO], STDOUT_FILENO) == DUP2_ERROR)
		return (perror("dup2"), exit(EXIT_FAILURE), ERROR);
	close_fds(cmd.fds);
	execve(cmd.m_path, cmd.m_args_split, cmd.info.envp);
	_print_error(cmd);
	return (exit(EXIT_FAILURE), ERROR);
}
