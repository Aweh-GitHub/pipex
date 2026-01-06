/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:32:54 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/06 17:50:02 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define NAME "pipex"
# define HEREDOC "here_doc"

# define ERR_ARGS_DEFAULT "pipex: syntax error \
<file_in> <cmd1> <cmd2> [cmd3] ... <file_out>\n"
# define ERR_ARGS_HEREDOC "pipex: syntax error \
<here_doc> <eof> <cmd1> <cmd2> [cmd3] ... <fileOut>\n"

# define REQUIRED_ARGC_DEFAULT 4
# define REQUIRED_ARGC_HEREDOC 6

# define ARG_INDEX_FILEIN 1
# define ARG_INDEX_FIRST_CMD 2
# define ARG_INDEX_HEREDOC_OFFSET 1

# define ARG_INDEX_HEREDOC 1
# define ARG_INDEX_HEREDOC_EOF 2

# define FD_IN 0
# define FD_OUT 1

# define CMD_ARGS_INDEX_NAME 0

# define DUP2_ERROR -1

# define EXIT_CMD_NOTFOUND 127

# include <stddef.h>
# include <sys/types.h>

typedef struct s_program_info
{
	int		argc;
	char	**argv;
	char	**envp;
}	t_program_info;

typedef struct s_cmd
{
	struct s_program_info	info;
	char					**m_args_split;
	char					*m_name;
	char					*m_path;
	int						fds[2];
}	t_cmd;

pid_t			exec_cmd(t_cmd cmd);
int				handle_here_doc(const char *eof);
pid_t			loop_to_exec_cmds(t_program_info info, int is_here_doc, int fd_f[2], int fd_p[2]);
void			close_all_fd(int fd_f[2], int fd_p[2], int fd_cmd[2]);
void			close_fds(int fds[2]);

t_cmd			t_cmd__new(char *argv_cmd, t_program_info info, int fdinout[2]);
void			t_cmd__free(t_cmd cmd);

t_program_info	t_program_args_info__new(int argc, char **argv, char **envp);

#endif