#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 16:11:01 by vpelivan          #+#    #+#              #
#    Updated: 2019/03/12 20:59:27 by vpelivan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = vpelivan.filler
FILES = main.c\
		tools.c\
		get_params.c
SRC = $(addprefix src/, $(FILES))
OBJ = $(SRC:src/%.c=.obj/%.o)
FLAGS = -Wall -Werror -Wextra
LIBCOM = -L libft -lft
INCLUDE = -I includes/ft_filler.h -I libft/includes/libft.h

all: $(NAME)

$(NAME): lib $(OBJ)
	gcc $(OBJ) $(INCLUDE) $(FLAGS) $(LIBCOM) -o $(NAME)

.obj/%.o: src/%.c
	mkdir -p .obj/
	gcc $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf .obj/
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all

lib:
	make -C libft

relib:
	make re -C libft