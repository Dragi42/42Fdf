# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 17:35:29 by dpaunovi          #+#    #+#              #
#    Updated: 2017/02/08 18:03:27 by dpaunovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAG = -lmlx -framework OpenGL -framework AppKit
OPTION = -o $(NAME)
SRC = main.c checkmap.c segment.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && make && make clean
	@gcc -L libft -lft $(OPTION) $(SRC) $(FLAG)
	@echo "\033[32mfdf created"

%.o: %.c
	@gcc -c -o $@ $<

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@echo "\033[36mFiles .o deleted"

fclean:
	@cd libft && make fclean
	@rm -f $(NAME) $(OBJ)
	@echo "\033[31mfdf deleted"

re: fclean all
