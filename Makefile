#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 13:31:30 by ebaudet           #+#    #+#              #
#    Updated: 2013/12/30 13:32:02 by ebaudet          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= pipex
SRCS	+= main.c
SRCS	+= function.c
SRCS	+= function2.c
SRCS	+= xenv.c
SRCS	+= ft_strsplit.c
OBJS	= ${SRCS:.c=.o}
INC		= ./
FLAGS	= -Wall -Wextra -Werror -pedantic

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(SRCS) -o $(NAME)
%.o: %.c
	gcc -c $< -o $@ $(FLAGS) -I$(INC)
gdb:
	cc -g $(FLAGS) $(SRCS) -o $(NAME)
	gdb $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
