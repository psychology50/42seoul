# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 13:05:15 by jayang            #+#    #+#              #
#    Updated: 2022/02/17 18:33:27 by jayang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CHLAGS = -Wall -Wextra -Werror

TARGET = do-op
SRCS = srcs/main.c srcs/ft_atoi.c srcs/ft_putstr.c srcs/ft_putchar.c srcs/ft_calculrator.c srcs/ft_putnbr.c
OBJS = ${SRCS:.c=.o}
HEADER = includes

%.o : %.c
	${CC} ${CHLAGS} -c -I ${HEADER} $< -o $@

${TARGET} : ${OBJS}
	${CC} ${CHLAGS} $^ -o $@

all : ${TARGET}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${TARGET}

re: fclean all