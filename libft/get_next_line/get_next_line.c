/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:13:38 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/16 12:57:46 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static t_file	*create_new_file(int fd)
{
	t_file	*new_file;

	new_file = malloc(sizeof(t_file));
	if (new_file == NULL)
		return (NULL);
	new_file->fd = fd;
	new_file->buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	new_file->next = NULL;
	new_file->prev = NULL;
	if (new_file->buf == NULL)
		return (free(new_file), NULL);
	ft_fileread(new_file);
	return (new_file);
}

static t_file	*get_file_by_fd(int fd, t_file **files)
{
	t_file	*query_file;
	t_file	*new_file;

	query_file = *files;
	while (query_file != NULL && query_file->next != NULL
		&& query_file->fd != fd)
		query_file = query_file->next;
	if (query_file != NULL && query_file->fd == fd)
		return (query_file);
	new_file = create_new_file(fd);
	if (new_file == NULL)
		return (NULL);
	if (*files == NULL)
		return (*files = new_file);
	new_file->prev = query_file;
	return (query_file->next = new_file);
}

static void	copy_and_extend(char *re_line, char *line, t_file *file,
		size_t ext_len)
{
	size_t	i;
	size_t	line_len;

	i = 0;
	while (line && line[i])
	{
		re_line[i] = line[i];
		i++;
	}
	line_len = i;
	i = 0;
	while (i < ext_len)
	{
		re_line[line_len + i] = file->buf[file->buf_i + i];
		i++;
	}
	re_line[line_len + i] = '\0';
	file->buf_i += i;
}

static char	*fill_line(char *line, t_file *file)
{
	char	*re_line;
	size_t	line_old_len;
	size_t	line_ext_len;

	if (file == NULL)
		return (NULL);
	if ((ssize_t)file->buf_i >= file->read_qty && ft_fileread(file) < 0)
		return (free(line), NULL);
	line_old_len = 0;
	while (line && line[line_old_len])
		line_old_len++;
	line_ext_len = 0;
	while (file->buf[file->buf_i + line_ext_len] != '\0'
		&& file->buf[file->buf_i + line_ext_len] != '\n')
		line_ext_len++;
	if (file->buf[file->buf_i + line_ext_len] == '\n')
		line_ext_len++;
	if (line_old_len + line_ext_len <= 0)
		return (free(line), NULL);
	re_line = malloc(sizeof(char) * (line_old_len + line_ext_len + 1));
	if (re_line == NULL)
		return (free(line), NULL);
	copy_and_extend(re_line, line, file, line_ext_len);
	free(line);
	return (re_line);
}

char	*get_next_line(int fd)
{
	static t_file	*files;
	t_file			*file;
	char			*line;

	file = get_file_by_fd(fd, &files);
	line = fill_line(NULL, file);
	while (line != NULL && !ft_is_line_completed(line, file))
		line = fill_line(line, file);
	if (file != NULL && line == NULL)
		files = ft_free_file(file, files);
	return (line);
}
