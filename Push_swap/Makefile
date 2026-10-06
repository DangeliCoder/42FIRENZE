# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 13:05:34 by ad-angel          #+#    #+#              #
#    Updated: 2024/09/30 13:05:56 by ad-angel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
BONUS = 

SRC =	push_swap.c \
		utils1.c \
		utils2.c \
		utils3.c \
		utils4.c \
		utils5.c \
		utils6.c \
		utils7.c
		
BONUS_SRC = checker.c \
		utils1.c \
		utils2.c \
		utils3.c \
		utils4.c

OBJ = ${SRC:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

${BONUS}: ${BONUS_OBJ} 
	${CC} ${FLAGS} ${BONUS_OBJ} -o ${BONUS}

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJ} ${BONUS_OBJ} ${NAME} ${BONUS}

fclean: clean
	${RM} ${NAME}

re: clean all

.PHONY: all clean fclean re bonus
