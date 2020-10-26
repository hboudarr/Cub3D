NAME 	= Cub3D

SRCS	= ./SRCS/parsing.c\
		  ./SRCS/parsing1.c\
		  ./SRCS/parsing2.c\
		  ./SRCS/parsing3.c\
		  ./SRCS/parsing4.c\
		  ./SRCS/main.c\
		  ./SRCS/hook.c\
		  ./SRCS/init.c\
		  ./SRCS/myray.c\
		  ./SRCS/myray2.c\
		  ./SRCS/myspriteray.c\
		  ./SRCS/sprite.c\
		  ./SRCS/tex.c\
		  ./SRCS/utile.c\
		  ./SRCS/exit.c\
		  ./SRCS/free.c\
		  ./SRCS/img.c\

OBJS	= ${SRCS:.c=.o}

LIBS	+= -lft
LIBS	+= -lmlx
LIBS	+= -lm


UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX_DIR = minilibx-linux
	LIBS += -lXext
	LIBS += -lX11
	SRCS += ./SRCS/key_linux.c

else
	MLX_DIR = minilibx_opengl_20191021
	LIBS += -framework OpenGL
	LIBS += -framework AppKit
	SRCS += ./SRCS/key.c
endif

LIBFT	= ./libft/libft.a

MLX		= $(MLX_DIR)/libmlx.a

HEADERS	=	-I ./includes/
HEADERS +=	-I ./libft/
HEADERS +=	-I $(MLX_DIR)

LIB_DIR	+= -L libft
LIB_DIR += -L $(MLX_DIR)

CFLAGS	= -Wall -Wextra -Werror

CC		= clang

.c.o:
			${CC} ${CFLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${LIBFT} $(MLX)
			${CC} $(LIB_DIR) -o ${NAME} ${OBJS} $(LIBS)

${LIBFT}:
			$(MAKE) -C ./libft
			
$(MLX):
			$(MAKE) 2>/dev/null -C $(MLX_DIR)

all:		${NAME}

clean:
	$(MAKE) -C ./libft fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
