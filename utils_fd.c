/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:08:35 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/03 16:46:38 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	close_fds(int fds[2])
{
	if (fds[0] != -1)
	{
		close(fds[0]);
		fds[0] = -1;
	}
	if (fds[1] != -1)
	{
		close(fds[1]);
		fds[1] = -1;
	}
}

void	close_all_fd(int fd_f[2], int fd_p[2], int fd_cmd[2])
{
	close_fds(fd_f);
	close_fds(fd_p);
	close_fds(fd_cmd);
}
