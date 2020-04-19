# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 18:56:49 by zexu              #+#    #+#              #
#    Updated: 2020/01/12 20:17:55 by zexu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = main.c \
	ft_printf.c \
	utils/ft_hextoa.c \
	utils/ft_itoa.c \
	utils/ft_ptoa.c \
	utils/ft_putstr_fd.c \
	utils/ft_strchr.c \
	utils/ft_strdup.c \
	utils/ft_strlen.c \
	utils/ft_strsub.c \
	utils/ft_uitoa.c \
	utils/ft_memmove.c \
	utils/ft_memcpy.c \
	format/pf_format_char.c \
	format/pf_format_int.c \
	format/pf_format_operations.c \
	format/t_pf_parse.c \
	format/t_pf.c \
	format/pf_flag_read_num.c

HEADER = ft_printf.h \
	utils/pf_utils.h \
	format/pf_format.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJ = ${SRC:.c=.o}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

compile:
	${CC} -g ${CFLAGS} ${SRC} -I ${HEADER}

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean all re
