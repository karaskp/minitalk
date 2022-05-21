# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 16:46:04 by mcouppe           #+#    #+#              #
#    Updated: 2022/05/21 18:54:25 by mcouppe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

SRC = ft_printf/ft_print_hexa.c ft_printf/ft_print_int.c ft_printf/ft_print_maj_hexa.c \
	ft_printf/ft_print_p.c ft_printf/ft_print_un.c ft_printf/ft_printf.c ft_printf/utils.c \
	server.c utils.c client.c utilsbis.c

OBJ = $(SRC:.c=.o)

CC = gcc

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

# need clean libft aswell
clean :
	$(RM) $(OBJ) ; cd libft/ ; make fclean

fclean : clean
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY : all clean fclean re libft
