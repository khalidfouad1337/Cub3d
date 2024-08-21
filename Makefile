# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 16:30:13 by kfouad            #+#    #+#              #
#    Updated: 2024/08/21 18:37:31 by kfouad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

CC = gcc

AR = ar -rc #create archive
# -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -rf # f = force | r = dir

LIBFT = libft/libft.a

SRCS = Cub3d.c check_id_stor_texture.c check_map_enclosed.c check_textures_colors.c read_map.c print_error.c

OBJ = ${SRCS:.c=.o}

%.o : %.c #targert : dependencies % = *
	   ${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJ}
		make -C libft -s
		${CC} $^ ${LIBFT} ${CFLAGS} -o $@

all: ${NAME}

clean:
		${RM} ${OBJ}
		make -C libft clean

fclean: clean
		make -C libft fclean
		${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re