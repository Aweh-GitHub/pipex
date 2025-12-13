# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 18:59:12 by thantoni          #+#    #+#              #
#    Updated: 2025/12/12 19:47:46 by thantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_isalpha.c							\
		ft_isdigit.c							\
		ft_isalnum.c							\
		ft_isascii.c							\
		ft_isprint.c							\
		ft_strlen.c								\
		ft_memset.c								\
		ft_bzero.c								\
		ft_memcpy.c								\
		ft_memmove.c							\
		ft_strlcpy.c							\
		ft_strlcat.c							\
		ft_toupper.c							\
		ft_tolower.c							\
		ft_strchr.c								\
		ft_strrchr.c							\
		ft_strncmp.c							\
		ft_memchr.c								\
		ft_memcmp.c								\
		ft_strnstr.c							\
		ft_atoi.c								\
		ft_calloc.c								\
		ft_strdup.c								\
		ft_substr.c								\
		ft_strjoin.c							\
		ft_strtrim.c							\
		ft_split.c								\
		ft_itoa.c								\
		ft_strmapi.c							\
		ft_striteri.c							\
		ft_putchar_fd.c							\
		ft_putstr_fd.c							\
		ft_putendl_fd.c							\
		ft_putnbr_fd.c							\
		ft_lstnew.c								\
		ft_lstadd_front.c						\
		ft_lstsize.c							\
		ft_lstlast.c							\
		ft_lstadd_back.c						\
		ft_lstdelone.c							\
		ft_lstclear.c							\
		ft_lstiter.c							\
		ft_lstmap.c								\
		extras/ft_arraytostr.c					\
		extras/ft_freesplit.c					\
		extras/ft_strjoin3.c					\
		extras/ft_first.c						\
		extras/ft_contains.c					\
		extras/ft_contains_v.c					\
		extras/ft_contains_at.c					\
		extras/ft_startwith.c					\
		extras/cfirst.c							\
		extras/clast.c							\
		extras/is_cfirst.c						\
		extras/is_clast.c						\
		extras/is_clast.c						\
		ter/ter_c.c								\
		ter/ter_i.c								\
		ter/ter_lu.c							\
		ter/ter_p.c								\
		ter/ter_s.c								\
		get_next_line/get_next_line.c			\
		get_next_line/get_next_line_utils.c		\
		ft_printf/ft_printf.c					\
		ft_printf/ft_printf_utils.c				\
		ft_printf/handlers/ft_printdefault.c	\
		ft_printf/handlers/ft_printchar.c		\
		ft_printf/handlers/ft_printstr.c		\
		ft_printf/handlers/ft_printptr.c		\
		ft_printf/handlers/ft_printdec.c		\
		ft_printf/handlers/ft_printudec.c		\
		ft_printf/handlers/ft_printhexlow.c		\
		ft_printf/handlers/ft_printhexupr.c		\
		ft_printf/handlers/ft_printpercent.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re