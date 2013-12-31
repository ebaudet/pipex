#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 13:31:30 by ebaudet           #+#    #+#              #
#    Updated: 2013/12/31 13:46:38 by apieropa         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# General options
CC		= gcc
RM		= /bin/rm
# Flags
CFLAGS	= -Wall -Wextra -Werror -pedantic
LDFLAGS	= -I $(DIR_INC)
# Directories
DIR_INC	= .
# Files
NAME	= pipex
SRC		+= main.c
SRC		+= function.c
SRC		+= function2.c
SRC		+= xenv.c
SRC		+= ft_strsplit.c
SRC		+= init_data.c
OBJ		= $(subst .c,.o,$(SRC))
INC		= pipex.h

# Classic Rules:
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(INC)
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# Additional Rules:
gdb:
	cc -g $(FLAGS) $(SRC) -o $(NAME)
	gdb $(NAME)
