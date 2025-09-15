# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 13:05:34 by ad-angel          #+#    #+#              #
#    Updated: 2024/12/19 13:24:06 by ad-angel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC=/usr/include
INCLIB=$(INC)/../lib
NAME = fdf
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
BONUS = 

SRC =	fdf.c \
	utils1.c \
	utils2.c \
	utils3.c \
	utils4.c \
	utils5.c \
	get_next_line.c \
	get_next_line_utils.c
		
BONUS_SRC = 

OBJ = ${SRC:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME} -L. -lmlx -L$(INCLIB) -lXext -lX11 -lm

${BONUS}: ${BONUS_OBJ} 
	${CC} ${FLAGS} ${BONUS_OBJ} -o ${BONUS} -L. -lmlx -L$(INCLIB) -lXext -lX11 -lm

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJ} ${BONUS_OBJ} ${NAME} ${BONUS}

fclean: clean
	${RM} ${NAME}

re: clean all

.PHONY: all clean fclean re bonus
