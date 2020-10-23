NAME 	= Cub3D

SRCS	= ./parsing.c\
		  ./parsing1.c\
		  ./parsing2.c\
		  ./parsing3.c\
		  ./parsing4.c\
		  ./main.c\
		  ./hook.c\
		  ./init.c\
		  ./myray.c\
		  ./myray2.c\
		  ./myspriteray.c\
		  ./sprite.c\
		  ./tex.c\
		  ./utile.c\
		  ./exit.c\
		  ./free.c\
		  ./img.c\

OBJS	= ${SRCS:.c=.o}

LIBS	+= -lft
LIBS	+= -lmlx
LIBS	+= -lm


UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX_DIR = minilibx-linux
	LIBS += -lXext
	LIBS += -lX11
	SRCS += key_linux.c
	#LIBS += -lbsd
else
	MLX_DIR = minilibx_opengl_20191021
	LIBS += -framework OpenGL
	LIBS += -framework AppKit
	SRCS += key.c
endif

LIBFT	= ./libft/libft.a

MLX		= $(MLX_DIR)/libmlx.a

HEADERS	=	-I ./includes/
HEADERS +=	-I ./libft/
HEADERS +=	-I $(MLX_DIR)

LIB_DIR	+= -L libft
LIB_DIR += -L $(MLX_DIR)

CFLAGS	= -Wall -Wextra -Werror
# CFLAGS	= -Wall -Wextra -Werror -fsanitize=address
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
