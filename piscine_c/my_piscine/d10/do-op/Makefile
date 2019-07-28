NAME = do-op

SRC = do_op.c lib.c op_func.c

${NAME}:
	gcc -Wall -Wextra -Werror ${SRC} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${NAME}

re: clean all
