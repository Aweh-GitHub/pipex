/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:50:58 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/16 13:21:50 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

ssize_t	ft_fileread(t_file *file)
{
	file->buf_i = 0;
	file->read_qty = read(file->fd, file->buf, BUFFER_SIZE);
	if (file->read_qty >= 0)
		file->buf[file->read_qty] = '\0';
	return (file->read_qty);
}

void	ft_free_all(t_file *files)
{
	t_file	*current;
	t_file	*to_free;

	current = files;
	while (current != NULL)
	{
		to_free = current;
		current = current->next;
		free((void *)to_free->buf);
		free((void *)to_free);
	}
}

t_file	*ft_free_file(t_file *file, t_file *files)
{
	if (file == NULL)
		return (files);
	if (file->prev != NULL)
		file->prev->next = file->next;
	else
		files = file->next;
	if (file->next != NULL)
		file->next->prev = file->prev;
	free(file->buf);
	free(file);
	return (files);
}

int	ft_is_line_completed(char *line, t_file *file)
{
	size_t	i;

	i = 0;
	while (line != NULL && line[i] != '\0' && line[i] != '\n')
		i++;
	if ((line != NULL && line[i] == '\n'))
		return (1);
	if (file == NULL || file->read_qty <= 0)
		return (1);
	return (0);
}
