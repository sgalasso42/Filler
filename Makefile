# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 17:12:19 by sgalasso          #+#    #+#              #
#    Updated: 2018/10/17 12:51:16 by sgalasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sgalasso.filler

SRC = main.c \
	  srcs/ft_free.c \
	  srcs/ft_get_el.c \
	  srcs/ft_strat_1.c \
	  srcs/ft_utils_strat_1.c \

OBJ = $(SRC:.c=.o)

INCLUDES = includes/

all: lib $(NAME)

$(NAME):	$(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) libft/libft.a $(OBJ) -I $(INCLUDES)

lib:
	make -C libft/

%.o: %.c $(INCLUDES)filler.h Makefile
	gcc -Wall -Wextra -Werror -o $@ -c $<

clean:
	rm -f $(OBJ) && make -C libft/ clean

fclean:		clean
	rm -f $(NAME) && make -C libft/ fclean

re:			fclean all

.PHONY : all clean fclean re
