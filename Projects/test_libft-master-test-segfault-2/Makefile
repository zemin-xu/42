# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asabotie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 13:40:41 by asabotie          #+#    #+#              #
#    Updated: 2019/10/31 11:57:50 by zexu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	test_libft

CC				=	gcc

TESTSRCSPATH	=	../libft

CFLAGS			=	-Wall -Werror -Wextra \
					-include includes/tests.h \
					-include ${TESTSRCSPATH}/libft.h

SRCSPATH		=	srcs

SRCS			=	${SRCSPATH}/main.c \
					${SRCSPATH}/tools.c \
					${SRCSPATH}/test_ft_memset.c \
					${SRCSPATH}/test_ft_bzero.c \
					${SRCSPATH}/test_ft_memcpy.c \
					${SRCSPATH}/test_ft_memccpy.c \
					${SRCSPATH}/test_ft_memmove.c \
					${SRCSPATH}/test_ft_memchr.c \
					${SRCSPATH}/test_ft_memcmp.c \
					${SRCSPATH}/test_ft_strlen.c \
					${SRCSPATH}/test_ft_isalpha.c \
					${SRCSPATH}/test_ft_isdigit.c \
					${SRCSPATH}/test_ft_isalnum.c \
					${SRCSPATH}/test_ft_isascii.c \
					${SRCSPATH}/test_ft_isprint.c \
					${SRCSPATH}/test_ft_toupper.c \
					${SRCSPATH}/test_ft_tolower.c \
					${SRCSPATH}/test_ft_strchr.c \
					${SRCSPATH}/test_ft_strrchr.c \
					${SRCSPATH}/test_ft_strncmp.c \
					${SRCSPATH}/test_ft_strlcpy.c \
					${SRCSPATH}/test_ft_strlcat.c \
					${SRCSPATH}/test_ft_strnstr.c \
					${SRCSPATH}/test_ft_atoi.c \
					${SRCSPATH}/test_ft_calloc.c \
					${SRCSPATH}/test_ft_strdup.c \
					${SRCSPATH}/test_ft_substr.c \
					${SRCSPATH}/test_ft_strjoin.c \
					${SRCSPATH}/test_ft_strtrim.c \
					${SRCSPATH}/test_ft_split.c \
					${SRCSPATH}/test_ft_itoa.c \
					${SRCSPATH}/test_ft_strmapi.c \
					${SRCSPATH}/test_ft_putchar_fd.c \
					${SRCSPATH}/test_ft_putstr_fd.c \
					${SRCSPATH}/test_ft_putendl_fd.c \
					${SRCSPATH}/test_ft_putnbr_fd.c \
					${SRCSPATH}/test_ft_lstnew.c \
					${SRCSPATH}/test_ft_lstadd_front.c \
					${SRCSPATH}/test_ft_lstsize.c \
					${SRCSPATH}/test_ft_lstlast.c \
					${SRCSPATH}/test_ft_lstadd_back.c \
					${SRCSPATH}/test_ft_lstdelone.c \
					${SRCSPATH}/test_ft_lstclear.c \
					${SRCSPATH}/test_ft_lstiter.c 
			
OBJS			=	${SRCS:.c=.o}

RM				=	rm -f

all:			${NAME}

${NAME}:		${OBJS}
				${CC} -o ${NAME} ${OBJS} -L${TESTSRCSPATH} -lft

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
