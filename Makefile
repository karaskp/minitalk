# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 16:46:04 by mcouppe           #+#    #+#              #
#    Updated: 2022/04/18 17:37:01 by mcouppe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SERVER = server

NAME = server

#CLIENT = client

SRC = ft_printf/ft_print_hexa.c ft_printf/ft_print_int.c ft_printf/ft_print_maj_hexa.c \
	ft_printf/ft_print_p.c ft_printf/ft_print_un.c ft_printf/ft_printf.c ft_printf/utils.c \
	server.c utils.c

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I.

RM = rm -f

all :  $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
