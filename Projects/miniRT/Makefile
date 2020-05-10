NAME = test
CC = cc
SRC = srcs/main.c

%.o: %.c
	$(CC) -Wall -Wextra -Werror ${SRC} -Imlx -c $< -o $@ -v

$(NAME): $(OBJ)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all