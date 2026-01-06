/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:26:11 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/06 16:27:03 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static char	*_get_path(char *name, char **envp)
{
	char	**paths;
	char	*result_path;
	size_t	path_i;

	if (name && name[0] == '/')
		return (ft_strdup(name));
	paths = ft_split(ft_first((void **)envp, "PATH=", \
		(int (*)(const void *, const void *))ft_startwith), ':');
	if (paths == NULL)
		return (NULL);
	path_i = 0;
	while (paths && paths[path_i])
	{
		result_path = ft_strjoin3(paths[path_i], "/", name);
		if (result_path == NULL)
			return (ft_freesplit(paths), result_path);
		if (access(result_path, X_OK) == 0)
			return (ft_freesplit(paths), result_path);
		free(result_path);
		path_i++;
	}
	if (paths)
		ft_freesplit(paths);
	return (NULL);
}

static char	*_get_name(char *argv_cmd)
{
	char	**split;
	char	*name;
	size_t	i;

	split = ft_split(argv_cmd, ' ');
	if (split == NULL)
		return (NULL);
	name = ft_strjoin("", split[0]);
	if (name == NULL)
		return (ft_freesplit(split), NULL);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (name);
}

t_cmd	t_cmd__new(char *argv_cmd, t_program_info info, int fdinout[2])
{
	t_cmd	cmd;

	cmd.fds[0] = fdinout[FD_IN];
	cmd.fds[1] = fdinout[FD_OUT];
	cmd.info = info;
	cmd.m_name = _get_name(argv_cmd);
	cmd.m_path = _get_path(cmd.m_name, cmd.info.envp);
	cmd.m_args_split = ft_split(argv_cmd, ' ');
	return (cmd);
}

void	t_cmd__free(t_cmd cmd)
{
	ft_freesplit(cmd.m_args_split);
	ft_free((void **)&cmd.m_name);
	ft_free((void **)&cmd.m_path);
}
