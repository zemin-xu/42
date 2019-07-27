# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zexu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 09:49:09 by zexu              #+#    #+#              #
#    Updated: 2019/06/26 19:30:59 by zexu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PATH_HEADER = ./includes/

SRC = ./srcs/

CFILES = ${SRC}ft_putchar.c ${SRC}ft_swap.c ${SRC}ft_putstr.c \
		 ${SRC}ft_strlen.c ${SRC}ft_strcmp.c

OBJS = ${CFILES:.c=.o}
	
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

$(NAME): ${OBJS} 
	ar rc ${NAME} ${OBJS}

.c.o:
	gcc ${CFLAGS} -I ${PATH_HEADER} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS}	

fclean: clean
	rm -f ${NAME}

re: fclean all
