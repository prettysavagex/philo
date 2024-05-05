CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread -g
RM = rm -rf

NAME = philo
SRC = 	control.c\
		die.c\
		init.c\
		main.c\
		parse.c\
		routine.c\
		time.c\
		utils.c\
		mutexdestroy.c\

${NAME}:
	${CC} ${CFLAGS} ${SRC} -o ${NAME}

all: ${NAME}

clean:

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re