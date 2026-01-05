/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_program_args_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:42:42 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/03 16:46:04 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_program_info	t_program_args_info__new(int argc, char **argv, char **envp)
{
	t_program_info	info;

	info.argc = argc;
	info.argv = argv;
	info.envp = envp;
	return (info);
}