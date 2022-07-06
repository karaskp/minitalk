# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 16:46:04 by mcouppe           #+#    #+#              #
#    Updated: 2022/07/06 20:45:03 by mcouppe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

SRC_SERVER = server.c 

SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

INC = minitalk.h

LIBFT = libft/libft.a

CC = gcc

LIB = -Llibft -lft

CFLAGS = -Wall -Werror -Wextra -I.

RM = rm -f

all :  $(SERVER) $(CLIENT)

$(SERVER) :	$(OBJ_SERVER) $(LIBFT) $(INC)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER) $(LIB)

$(CLIENT) :	$(OBJ_CLIENT) $(LIBFT) $(INC)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT) $(LIB)

$(LIBFT):
	$(MAKE) -C libft

clean :
	$(MAKE) -C libft clean
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean : 	clean
	$(MAKE) -C libft fclean
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY : all clean fclean re
