# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 17:01:53 by prambaud          #+#    #+#              #
#    Updated: 2024/12/11 14:53:26 by prambaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
LIBFT       = libft/libft.a
MLX         = mlx_linux/libmlx.a
SRCS        = ./mlx/ft_map_setup.c \
              ./mlx/main.c \
              ./mlx/ft_map_checker.c \
			  ./mlx/ft_map_checker2.c \
              ./mlx/ft_moves.c \
              ./mlx/ft_moves2.c \
              ./mlx/ft_images_load.c \
              ./mlx/ft_backtracking.c

OBJS        = ${SRCS:.c=.o}
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
RM          = rm -rf

# Construction de l'exécutable
${NAME}: ${LIBFT} ${MLX} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -Lmlx_linux -lmlx -L/usr/lib \
		-Imlx_linux -lXext -lX11 -lm  -lz -Llibft -lft -o ${NAME}

# Compilation de libft
${LIBFT}:
	make -C libft

# Compilation de libmlx
${MLX}:
	make -C mlx_linux

# Transformation des .c en .o
.c.o:
	${CC} ${CFLAGS} -Imlx_linux -c $< -o $@

# Règles principales
all: ${NAME}

clean:
	make clean -C libft
	make clean -C mlx_linux
	${RM} ${OBJS}

fclean: clean
	make fclean -C libft
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
