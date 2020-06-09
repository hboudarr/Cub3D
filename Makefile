CHM		=	./

LIBFT	= ./libft/libft.a

SRCS	=

OBJS	= ${SRCS:.c=.o}

HEADERS	= ./includes./cub3d.h

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

NAME	=	libftcub3d.a

.c.o:
			${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
	$(MAKE) clean -C ./libft
	rm -f ${OBJS}

fclean:		clean
			$(MAKE) clean -C ./libft
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
