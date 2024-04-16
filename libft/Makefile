# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 11:41:37 by ad-angel          #+#    #+#              #
#    Updated: 2023/10/19 11:41:39 by ad-angel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target library
NAME = libft.a

all : $(NAME)

$(NAME) :
	cc -Wall -Wextra -Werror -c *.c
	ar -crsv $(NAME) *.o
	ranlib $(NAME)

bonus :
	cc -Wall -Wextra -Werror -c *.c
	ar -crsv $(NAME) *.o
	ranlib $(NAME)

re :

fclean : clean
	rm -f *.a

clean :
	rm -f *.o

so:
	cc -fPIC -Wall -Wextra -Werror -c *.c
	gcc -shared -o libft.so *.o

