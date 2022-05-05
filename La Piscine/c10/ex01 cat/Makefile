# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 16:18:09 by jayang            #+#    #+#              #
#    Updated: 2022/02/19 17:15:41 by jayang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CHLAGS = -Wall -Wextra -Werror

TARGET = ft_cat
SRCS = srcs/main.c srcs/string.c
OBJS = ${SRCS:.c=.o}

%.o : %.c
	${CC} ${CHLAGS} -c $< -o $@

${TARGET} : ${OBJS}
	${CC} ${CHLAGS} $^ -o $@

all : ${TARGET}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${TARGET}

re: fclean all