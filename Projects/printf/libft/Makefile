# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 18:55:23 by zexu              #+#    #+#              #
#    Updated: 2019/11/07 18:55:27 by zexu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# Makefile is a file to describe the way construct a project
# in order to realise automatic compliation and construcion
#
# The command "make" will analyse and execute Makefile
# We can use "make -f filename" to designate the file to analyse,
# in default, it is called "Makefile".
#
# A makefile will contain targets, commands and variables
# target is the file that we want to create
# command is the steps to execute to make the target
#
# When we execute "make filename", this program will examinate whether 
# "filename" exists, and it will execute the corresponding commands
# to make it if it doesn't exist
#
# The items after the colon of target is called "dependency"
# each item should be a target in this makefile or an existing file
# in order to construct current target, we need to construct
# all the dependencies firstly
# Attention: if the modification time of a dependency is later than the
# creation time of corresponding target, makefile will re-create the target
#
# Makefile is not a script and has no the executing order
# we should treat it as a general principle sets
#
# We cannot define serveral commands for a same "target"
# if it occurs, the program will execute the last commands
#
# a command start with "tab"
#
# according to the description of target, we will realise that 
# we don't have to create a file by using target, we can also
# define some "target" to execute somethings, ex, clean
# if the file with same name exists, we can use ".PHONY" to differenciate them
#
# "$<": the first dependency
# "$^": all dependencies
# "$@": target

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
ft_memmove.c ft_memchr.c ft_memcmp.c \
ft_strlen.c ft_strdup.c \
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
ft_strncmp.c ft_atoi.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c \
ft_strmapi.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_split.c \
ft_itoa.c \
ft_putchar_fd.c ft_strlcpy.c ft_calloc.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

HEADER = libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJ = ${SRC:%.c=%.o}

OBJ_BONUS = ${SRC_BONUS:%.c=%.o}

$(NAME): ${OBJ}
	ar rcs ${NAME} ${OBJ}

all: ${NAME}

${OBJ}:
	${CC} ${CFLAGS} -I ${HEADER} -c ${SRC}

${OBJ_BONUS}:
	${CC} ${CFLAGS} -I ${HEADER} -c ${SRC_BONUS}

bonus: ${OBJ} ${OBJ_BONUS}
	ar rcs ${NAME} ${OBJ} ${OBJ_BONUS} 

clean:
	${RM} ${OBJ} ${OBJ_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean all re
