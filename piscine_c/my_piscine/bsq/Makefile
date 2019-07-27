# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zexu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 15:35:39 by zexu              #+#    #+#              #
#    Updated: 2019/06/26 23:35:37 by zexu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq 

SRCS = *.c 

HEADER = bsq.h

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I $(HEADER) -o $(NAME) $(SRCS)

clean:

fclean: clean 
	rm -f $(NAME)
