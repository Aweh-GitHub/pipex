/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:39:24 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 16:38:08 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static int	exec_cmd(t_cmd *cmd)
{
	pid_t	pid;

	if (cmd == NULL)
		return (ERROR);
	pid = fork();
	if (pid > 0)
		return (close_fds(cmd->fds->fds), t_cmd__free(cmd), TRUE);
	if (pid < 0)
		return (t_cmd__free(cmd), perror("fork"), exit(EXIT_FAILURE), ERROR);
	if (dup2(cmd->fds->fds[STDIN_FILENO], STDIN_FILENO) == DUP2_ERROR)
		return (perror("dup2"), exit(EXIT_FAILURE), ERROR);
	if (dup2(cmd->fds->fds[STDOUT_FILENO], STDOUT_FILENO) == DUP2_ERROR)
		return (perror("dup2"), exit(EXIT_FAILURE), ERROR);
	close(cmd->fds->fds[STDIN_FILENO]);
	close(cmd->fds->fds[STDOUT_FILENO]);
	execve(cmd->path, cmd->args, cmd->envp);
	ft_putstr_fd(cmd->name, STDERR_FILENO);
	if (cmd->name && cmd->name[0] == '/')
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	else
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
	return (ERROR);
}

static int	handle_here_doc(const char *eof)
{
	int		pipefds[2];
	char	*line;

	if (pipe(pipefds) == -1)
		return (perror("heredoc"), exit(EXIT_FAILURE), -1);
	while (TRUE)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			return (close(pipefds[1]), get_next_line(GNL_WIPE), \
				pipefds[0]);
		if (ft_contains(line, eof) && line[ft_strlen(eof)] == '\n')
			return (free(line), close(pipefds[1]), \
				get_next_line(GNL_WIPE), pipefds[0]);
		ft_putstr_fd(line, pipefds[1]);
		free(line);
	}
	get_next_line(GNL_WIPE);
	close(pipefds[1]);
	return (pipefds[0]);
}

static void	init_fdfiles(int *fd_files, int is_heredoc, int argc, char **argv)
{
	char	*fileout;

	fileout = argv[argc - 1];
	if (is_heredoc)
		fd_files[FD_IN] = handle_here_doc(argv[ARG_INDEX_HEREDOC_EOF]);
	else
		fd_files[FD_IN] = open(argv[ARG_INDEX_FILEIN], O_RDONLY);
	if (is_heredoc)
		fd_files[FD_OUT] = open(fileout, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd_files[FD_OUT] = open(fileout, O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

void	verify_args(int is_heredoc, int argc)
{
	if (!is_heredoc && argc < 4)
	{
		ft_printf(ERR_ARGS_DEFAULT);
		exit(EXIT_FAILURE);
	}
	else if (is_heredoc && argc < 5)
	{
		ft_printf(ERR_ARGS_HEREDOC);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_f[2];
	int		fd_p[2];
	int		fd_cmd[2];
	int		is_heredoc;
	int		i;

	is_heredoc = ft_contains(argv[ARG_INDEX_HEREDOC], HEREDOC);
	init_fdfiles(fd_f, is_heredoc, argc, argv);
	verify_args(is_heredoc, argc);
	fd_cmd[FD_IN] = fd_f[FD_IN];
	i = ARG_INDEX_FIRST_CMD + ter_lu(is_heredoc, ARG_INDEX_HEREDOC_OFFSET, 0);
	while (i < argc - 1)
	{
		if (pipe(fd_p) == -1)
			return (perror("pipe"), exit(EXIT_FAILURE), EXIT_FAILURE);
		fd_cmd[FD_OUT] = ter_i(i == argc - 2, fd_f[FD_OUT], fd_p[1]);
		exec_cmd(t_cmd__new(argv[i], envp, fd_cmd));
		close(fd_p[1]);
		fd_cmd[FD_IN] = fd_p[0];
		i++;
	}
	close_all_fd(fd_f, fd_p, fd_cmd);
	return (EXIT_SUCCESS);
}
