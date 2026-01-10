# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 11:14:14 by thantoni          #+#    #+#              #
#    Updated: 2026/01/10 12:52:34 by thantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c							\
		handler_cmd.c					\
		handler_here_doc.c				\
		handler_loop.c					\
		handle_fd_init_mode.c	\
		utils_fd.c						\
		t_program_args_info.c			\
		t_cmd.c							\
		t_fds.c			

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re