# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 15:14:13 by jayang            #+#    #+#              #
#    Updated: 2022/02/21 20:57:37 by jayang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CHLAGS = -Wall -Wextra -Werror

NAME = ft_hexdump
SRCS = srcs/main.c srcs/string.c srcs/print_hex_n.c srcs/print_hex_o.c srcs/ft_error_ctrl.c
OBJS = ${SRCS:.c=.o}
HEADER = includes

%.o : %.c
	${CC} ${CHLAGS} -I ${HEADER} -c $< -o $@

${NAME} : ${OBJS}
	${CC} ${CHLAGS} $^ -o $@

all : ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all