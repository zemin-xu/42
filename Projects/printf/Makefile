# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 18:56:49 by zexu              #+#    #+#              #
#    Updated: 2019/11/07 19:40:19 by zexu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB_PATH = libft/

SRC = ft_printf.c

HEADER = ft_printf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJ = ${SRC:%.c=%.o}

$(NAME):  
	lib_make
	${OBJ}

lib_make:
	@make -C ${LIB_PATH}

all: ${NAME}

${OBJ}:
	${CC} ${CFLAGS} -I ${HEADER} -c ${SRC}

clean:
	${RM} ${OBJ} ${OBJ_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean all re
