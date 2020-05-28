CHM		=	./

SRCS	=

OBJS	= ${SRCS:.c=.o}

HEADERS	= ./includes/cub3d.h

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

NAME	=	cub3d.a

LIB = -L ./libft -lft

.c.o:
			${CC} ${CFLAGS} -I ${HEADERS} ${LIB}  ./libft/libft.a -o -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
