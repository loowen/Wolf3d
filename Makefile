# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhamlyn <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 10:03:48 by lhamlyn           #+#    #+#              #
#    Updated: 2016/12/08 12:46:24 by lhamlyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c keys.c raycasting.c colours.c draw_line.c time.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra

ATTACH = -L libft/ -lft -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME) :
	@make -C libft/ fclean
	@make -C libft/
	@clang $(CFLAG) -I lbft/ -c $(SRC)
	@clang $(CFLAG) -o $(NAME) $(OBJ) $(ATTACH)
	@rm -Rf $(OBJ)

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

norme:
	@norminette $(SRC) wolf.h

q:
	@clang -I lbft/ -C $(SRC)
	@clang $(CFLAG) -o $(NAME) $(OBJ) $(ATTACH)
	@make clean

run:
	@./wolf3d map

qr: q run

me:
	@rm -Rf author
	@whoami > author
