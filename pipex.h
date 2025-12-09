/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:32:54 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/09 16:02:45 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define HEREDOC "here_doc"

# define ARG_INDEX_FILEIN 1
# define ARG_INDEX_FIRST_CMD 2
# define ARG_INDEX_HEREDOC_OFFSET 1

# define ARG_INDEX_HEREDOC 1
# define ARG_INDEX_HEREDOC_EOF 2

# define FD_IN 0
# define FD_OUT 1

# define CMD_ARGS_INDEX_NAME 0

# define DUP2_ERROR -1

# include <stddef.h>

typedef struct s_fds
{
	int	fds[2];
}	t_fds;

typedef struct s_cmd
{
	char	**envp;
	char	**args;
	char	*name;
	char	*path;
	t_fds	*fds;
}	t_cmd;

t_cmd	*t_cmd__new(char *argv_cmd, char **envp, int fdinout[2]);
void	t_cmd__free(t_cmd *cmd);

t_fds	*t_fds__new(int fd_in, int fd_out);
void	t_fds__free(t_fds *fds);

#endif