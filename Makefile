# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 16:30:13 by kfouad            #+#    #+#              #
#    Updated: 2024/08/16 18:06:20 by kfouad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

CC = gcc

AR = ar -rc #create archive

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf # f = force | r = dir

LIBFT = libft/libft.a

SRCS = Cub3d.c

OBJ = ${SRCS:.c=.o}

%.o : %.c #targert : dependencies % = *
	   ${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJ}
		make -C libft -s
		${CC} $^ ${LIBFT} -o $@

all: ${NAME}

clean:
		${RM} ${OBJ}
		make -C libft clean

fclean: clean
		make -C libft fclean
		${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re