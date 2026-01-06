/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_here_doc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:33:10 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/06 10:34:28 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

static void	_write_heredoc(int fd, const char *eof)
{
	char	*line;

	while (TRUE)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, eof, ft_strlen(eof)) == 0
			&& line[ft_strlen(eof)] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
}

int	handle_here_doc(const char *eof)
{
	int		fd;

	fd = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return (perror("heredoc"), exit(EXIT_FAILURE), -1);
	_write_heredoc(fd, eof);
	get_next_line(GNL_WIPE);
	close(fd);
	fd = open(".heredoc_tmp", O_RDONLY);
	if (fd == -1)
		return (unlink(".heredoc_tmp"), perror("heredoc"), exit(EXIT_FAILURE), -1);
	unlink(".heredoc_tmp");
	return (fd);
}