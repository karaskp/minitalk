# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 15:38:34 by mcouppe           #+#    #+#              #
#    Updated: 2022/07/12 12:51:44 by mcouppe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_isascii.c ft_isprint.c \
      	ft_itoa.c ft_memchr.c ft_memcmp.c \
      	ft_memcpy.c ft_memset.c ft_putchar_fd.c \
      	ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c \
	ft_strdup.c ft_strjoin.c ft_strlcpy.c \
	ft_strlen.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c \
	ft_bzero.c ft_calloc.c  ft_memmove.c \
	ft_split.c ft_printf.c ft_print_hexa.c \
	ft_print_int.c ft_print_maj_hexa.c ft_print_p.c \
	ft_print_un.c ft_printf_utils.c ft_binaryconvert.c \
	ft_error.c ft_putendl_fd.c


OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = /bin/rm -f

all : $(NAME) 

$(NAME) :
	$(CC) -c $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME) bonus

re : fclean all


.PHONY : all clean fclean re 
