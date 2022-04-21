# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 16:46:04 by mcouppe           #+#    #+#              #
#    Updated: 2022/04/21 17:11:00 by mcouppe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

SRC = ft_printf/ft_print_hexa.c ft_printf/ft_print_int.c ft_printf/ft_print_maj_hexa.c \
	ft_printf/ft_print_p.c ft_printf/ft_print_un.c ft_printf/ft_printf.c ft_printf/utils.c \
	server.c utils.c client.c utilsbis.c

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I.

RM = rm -f

all :  $(SERVER) $(CLIENT)

libft : 
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(SERVER) : server.o libft
	 $(CC) $(CFLAGS) -o $@ $< -Llibft -lft

$(CLIENT) : client.o libft
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY : all clean fclean re libft
