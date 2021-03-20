# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makfile                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 15:21:58 by aeddaqqa          #+#    #+#              #
#    Updated: 2019/09/30 14:31:51 by aeddaqqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c mouse_hook.c mandelbrot.c calcul.c julia.c key_press.c color.c\
		multibrot.c fein.c draw.c menu.c init.c key_press2.c key_press3.c\
		mouse_press2.c mouse_press3.c

NAME = fractol

mlx1 = gcc -Wall -Wextra -Werror -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 

OBJ = $(SRC:.c=.o)

all : $(NAME)
$(NAME) : $(OBJ)
	$(mlx1) $^ -o $@
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all
