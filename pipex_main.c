/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:39:24 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/09 17:18:48 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static void	exec_cmd(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
		return (t_cmd__free(cmd));
	if (pid < 0)
		return (t_cmd__free(cmd), perror("fork"), exit(EXIT_FAILURE));
	if (dup2(cmd->fds->fds[STDIN_FILENO], STDIN_FILENO) == DUP2_ERROR)
		return (perror("dup2"), exit(EXIT_FAILURE));
	if (dup2(cmd->fds->fds[STDOUT_FILENO], STDOUT_FILENO) == DUP2_ERROR)
		return (perror("dup2"), exit(EXIT_FAILURE));
	close(cmd->fds->fds[STDIN_FILENO]);
	close(cmd->fds->fds[STDOUT_FILENO]);
	execve(cmd->path, cmd->args, cmd->envp);
	ft_putstr_fd(cmd->name, STDERR_FILENO);
	if (cmd->name[0] == '/')
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	else
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static size_t	get_argv_cmdindex(int is_heredoc)
{
	size_t	cmd_i;

	cmd_i = ARG_INDEX_FIRST_CMD;
	if (is_heredoc)
		cmd_i += ARG_INDEX_HEREDOC_OFFSET;
	return (cmd_i);
}

static int	handle_here_doc(const char *eof)
{
	int		pipefds[2];
	char	*line;

	if (pipe(pipefds) == -1)
		return (perror("heredoc"), exit(EXIT_FAILURE), -1);
	while (TRUE)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			return (close(pipefds[1]), pipefds[0]);
		if (ft_contains(line, eof) && line[ft_strlen(eof)] == '\n')
			return (free(line), close(pipefds[1]), pipefds[0]);
		ft_putstr_fd(line, pipefds[1]);
		free(line);
	}
	close(pipefds[1]);
	return (pipefds[0]);
}

static void	init_fdfiles(int *fd_files, int is_heredoc, int argc, char **argv)
{
	char *fileout;

	fileout = argv[argc - 1];
	if (is_heredoc)
	{
		fd_files[FD_IN] = handle_here_doc(argv[ARG_INDEX_HEREDOC_EOF]);
		fd_files[FD_OUT] = open(fileout, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		fd_files[FD_IN] = open(argv[ARG_INDEX_FILEIN], O_RDONLY);
		fd_files[FD_OUT] = open(fileout, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	}
	if (fd_files[FD_IN] == -1)
		return (perror(argv[1]), exit(EXIT_FAILURE), (void)init_fdfiles);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_files[2];
	int		fd_pipe[2];
	int		fd_cmd[2];
	int		is_heredoc;
	int		i;

	is_heredoc = ft_contains(argv[ARG_INDEX_HEREDOC], HEREDOC);
	init_fdfiles(fd_files, is_heredoc, argc, argv);
	fd_cmd[FD_IN] = fd_files[FD_IN];
	i = get_argv_cmdindex(is_heredoc);
	while (i < argc - 1)
	{
		if (pipe(fd_pipe) == -1)
			return (perror("pipe"), exit(EXIT_FAILURE), EXIT_FAILURE);
		fd_cmd[FD_OUT] = ter_i(i == argc - 2, fd_pipe[1], fd_files[FD_OUT]);
		exec_cmd(t_cmd__new(argv[i], envp, fd_cmd));
		close(fd_pipe[1]);
		fd_cmd[FD_IN] = fd_pipe[0];
		i++;
	}
	close(fd_pipe[0]);
	close(fd_files[FD_IN]);
	close(fd_files[FD_OUT]);
	return (EXIT_SUCCESS);
}
