# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 14:19:59 by arosas-j          #+#    #+#              #
#    Updated: 2023/09/12 15:19:50 by arosas-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = ar rcs

SRC = ft_formats.c \
	ft_hexadecimal.c \
	ft_print_arg.c \
	ft_printf.c \
	ft_utils.c \
	ft_itoa.c \
	ft_strlcpy.c \
	ft_uitoa.c \

OBJ = ${SRC:.c=.o}

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re