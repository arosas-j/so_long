NAME	= so_long
B_NAME	= so_long_bonus
LIBMLX	= ./MLX42
LIBFT	= ./libft
LIBPF	= ./ft_printf

HEADERS	= -I ./includes -I ${LIBMLX}/include -I ${LIBFT} -I ${LIBPF}
LIBGL	= -lglfw -L"/Users/arosas-j/.brew/opt/glfw/lib"
LIBS	= ${LIBGL} ${LIBMLX}/libmlx42.a ${LIBFT}/libft.a ${LIBPF}/libftprintf.a
SRCS	= main.c game.c checks.c checks_utils.c map.c image.c keys.c free.c image_utils.c
B_SRCS	= main.c game.c checks_bonus.c checks_utils.c map.c image.c keys.c free.c image_utils.c

OBJS	= ${SRCS:.c=.o}
B_OBJS	= ${B_SRCS:.c=.o}

all: libft libmlx libpf ${NAME}

bonus: libft libmlx libpf ${B_NAME}

libft:
	@${MAKE} -C ${LIBFT}

libmlx:
	@${MAKE} -C ${LIBMLX}

libpf:
	@${MAKE} -C ${LIBPF}

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}
	@${CC} ${DFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

${B_NAME}: ${B_OBJS}
	@${CC} ${DFLAGS} ${B_OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -f ${OBJS}
	@rm -f ${B_OBJS}
	@${MAKE} -C ${LIBFT} clean
	@${MAKE} -C ${LIBMLX} clean
	@${MAKE} -C ${LIBPF} clean

fclean: clean
	@rm -f ${NAME}
	@${MAKE} -C ${LIBFT} fclean
	@${MAKE} -C ${LIBMLX} fclean
	@${MAKE} -C ${LIBPF} fclean
	
re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft