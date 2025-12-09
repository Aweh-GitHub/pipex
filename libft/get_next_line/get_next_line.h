/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:13:00 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/08 11:07:14 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stddef.h>
# include <sys/types.h>

typedef struct s_file
{
	char			*buf;
	size_t			buf_i;
	ssize_t			read_qty;
	int				fd;
	struct s_file	*next;
	struct s_file	*prev;
}	t_file;

ssize_t	ft_fileread(t_file *file);
void	ft_free_all(t_file *files);
t_file	*ft_free_file(t_file *file, t_file *files);
int		ft_is_line_completed(char *line, t_file *file);

#endif
