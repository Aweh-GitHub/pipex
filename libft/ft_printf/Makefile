# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 16:41:21 by thantoni          #+#    #+#              #
#    Updated: 2025/11/12 20:46:59 by thantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c					\
		ft_printf_utils.c			\
		handlers/ft_printdefault.c	\
		handlers/ft_printchar.c		\
		handlers/ft_printstr.c		\
		handlers/ft_printptr.c		\
		handlers/ft_printdec.c		\
		handlers/ft_printudec.c		\
		handlers/ft_printhexlow.c	\
		handlers/ft_printhexupr.c	\
		handlers/ft_printpercent.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re