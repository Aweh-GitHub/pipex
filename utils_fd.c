/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:08:35 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/13 16:32:06 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	close_all_fd(int fd_f[2], int fd_p[2], int fd_cmd[2])
{
	close(fd_f[0]);
	close (fd_f[1]);
	close(fd_p[0]);
	close(fd_p[1]);
	close(fd_cmd[0]);
	close(fd_cmd[1]);
}
