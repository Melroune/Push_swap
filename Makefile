# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/26 01:48:34 by akerkeb           #+#    #+#              #
#    Updated: 2015/01/26 01:56:31 by akerkeb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

SRC=push_swap.c ft_atoi.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
ft_putendl_fd.c ft_putstr.c ft_putstr_fd.c ft_putnbr.c fonc_tri.c \
options.c ft_strlen.c ft_strncmp.c fonc_tri1.c fonc_tri2.c \
opt_bonnus.c fonc_tri3.c ft_itoa.c ft_strequ.c ft_memalloc.c \
ft_bzero.c ft_memset.c

FLAGS= -Wall -Wextra -Werror

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) 

%.o: %.c
	gcc -c -ggdb3 $^ $(FLAGS) 

clean:
		rm -rf $(OBJ)
fclean: clean
		rm -rf $(NAME)
re: fclean all


