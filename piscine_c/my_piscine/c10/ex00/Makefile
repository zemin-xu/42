# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zexu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 09:49:09 by zexu              #+#    #+#              #
#    Updated: 2019/06/24 14:14:00 by zexu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file 

CFILES = ft_display_file.c

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc ${CFLAGS} -o ${NAME} ${CFILES}

clean:
	/bin/rm -f ${TEMPS}	

fclean: clean
	/bin/rm -f ${NAME}

re: fclean all
