# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zexu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 15:35:39 by zexu              #+#    #+#              #
#    Updated: 2019/06/23 23:09:58 by zexu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush_02

SRCS = split.c string.c main.c 

HEADER = rush_02.h

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I $(HEADER) -o $(NAME) $(SRCS)

clean:

fclean: clean 
	rm -f $(NAME)
