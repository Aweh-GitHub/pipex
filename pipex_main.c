/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:39:24 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/05 15:41:54 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(int argc, char **argv, char **envp)
{
	t_program_info	info;
	int				fd_f[2];
	int				fd_p[2];

	if (argc <= 4)
		return (ft_printf(ERR_ARGS_DEFAULT), EXIT_FAILURE);
	info = t_program_args_info__new(argc, argv, envp);
	loop_to_exec_cmds(info, fd_f, fd_p);
	close_fds(fd_f);
	while (wait(NULL) > 0)
		;
	return (EXIT_SUCCESS);
}
