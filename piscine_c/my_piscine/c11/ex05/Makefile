# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zexu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/27 09:20:19 by zexu              #+#    #+#              #
#    Updated: 2019/06/27 09:32:55 by zexu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRC = *.c

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: compile

compile:
	gcc ${CFLAGS} -o ${NAME} ${SRC}

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all
