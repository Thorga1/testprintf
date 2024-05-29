# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tordner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 15:28:00 by tordner           #+#    #+#              #
#    Updated: 2024/05/29 14:05:49 by tordner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc

CFLAGS		= -Wall -Wextra -Werror

SRCS	= ft_printf.c \
	  generic_functions.c \
	  more_generic_functions.c \
	  flag_hexa.c \
	  flag_fncs.c \
	  flag_ptr.c

OBJ	= $(SRCS:.c=.o)

NAME	= libftprintf.a

$(NAME):	$(OBJ)
	ar rsc $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) -f $(OBJ)

fclean:	clean
	$(RM) -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
