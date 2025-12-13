/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:26:11 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/13 16:16:29 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static char	*get_path(char *name, char **envp)
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

char	*get_name(char *argv_cmd)
{
	char	**split;
	char	*name;
	size_t	i;

	split = ft_split(argv_cmd, ' ');
	name = ft_strdup(split[0]);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (name);
}

t_cmd	*t_cmd__new(char *argv_cmd, char **envp, int fdinout[2])
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->fds = t_fds__new(fdinout[FD_IN], fdinout[FD_OUT]);
	if (cmd->fds == NULL)
		return (t_cmd__free(cmd), NULL);
	cmd->envp = envp;
	cmd->name = get_name(argv_cmd);
	cmd->path = get_path(cmd->name, cmd->envp);
	if (cmd->path == NULL)
		return (t_cmd__free(cmd), NULL);
	cmd->args = ft_split(argv_cmd, ' ');
	if (cmd->args == NULL)
		return (t_cmd__free(cmd), NULL);
	return (cmd);
}

void	t_cmd__free(t_cmd	*cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->fds)
		t_fds__free(cmd->fds);
	if (cmd->args)
		ft_freesplit(cmd->args);
	if (cmd->name)
		free(cmd->name);
	if (cmd->path)
		free(cmd->path);
	free(cmd);
}
