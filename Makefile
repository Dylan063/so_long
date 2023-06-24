# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 09:32:49 by dravaono          #+#    #+#              #
#    Updated: 2023/06/19 18:07:20 by dravaono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c 		\
	so_long_utils.c \
	parsing.c 		\
	path.c			\
	init_mlx.c		


OBJS = ${SRCS:.c=.o}
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
LIBFT = ./libft

all : ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libft/
	${CC} -o ${NAME} ${CFLAGS} ./libft/libft.a ${OBJS} ${MLX_FLAGS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${MAKE} clean -C ./libft/
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re
