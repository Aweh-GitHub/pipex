/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:10:39 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/10 15:59:53 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>

static void	_print_error(t_cmd cmd)
{
	ft_putstr_fd(cmd.m_name, STDERR_FILENO);
	if (cmd.m_name && cmd.m_name[0] == '/')
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	else
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
}

static void	_exec_child(t_cmd cmd)
{
	if (dup2(cmd.fds[STDIN_FILENO], STDIN_FILENO) == DUP2_ERROR
		|| dup2(cmd.fds[STDOUT_FILENO], STDOUT_FILENO) == DUP2_ERROR)
	{
		close_fds(cmd.fds);
		t_cmd__free(cmd);
		exit(EXIT_FAILURE);
	}
	close_fds(cmd.fds);
	if (cmd.m_path != NULL)
	{
		execve(cmd.m_path, cmd.m_args_split, cmd.info->envp);
		perror(cmd.m_name);
		t_cmd__free(cmd);
		if (errno == EACCES || errno == EISDIR)
			exit(126);
		exit(127);
	}
	_print_error(cmd);
	t_cmd__free(cmd);
	exit(EXIT_CMD_NOTFOUND);
}

pid_t	handle_cmd(t_cmd cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		t_cmd__free(cmd);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		_exec_child(cmd);
	t_cmd__free(cmd);
	return (pid);
}
