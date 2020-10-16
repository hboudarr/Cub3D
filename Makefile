CHM		=	./

LIBFT	= ./libft/libft.a

SRCS	= ./parsing.c\
		  ./parsing1.c\
		  ./parsing2.c\
		  ./parsing3.c\
		  ./parsing4.c\
		  ./main.c\
		  ./hook.c\
		  ./init.c\
		  ./myray.c\
		  ./myspriteray.c\
		  ./sprite.c\
		  ./tex.c\
		  ./utile.c\
		  ./exit.c\
		  ./free.c\
		  ./img.c\

OBJS	= ${SRCS:.c=.o}

HEADERS	= ./includes/cub3d.h

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

NAME 	= Cub3D
#NAME	=	libftcub3d.a

.c.o:
			${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
		#	ar rc ${NAME} ${OBJS}
			${CC} ${CFLAGS} -I ${HEADERS} ${OBJS} -lmlx -lXext -lX11 -lm -lbsd -o ${NAME}
			

all:		${NAME}

clean:
	$(MAKE) clean -C ./libft
	rm -f ${OBJS}

fclean:		clean
			$(MAKE) clean -C ./libft
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
