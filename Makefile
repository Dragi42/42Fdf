# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 17:35:29 by dpaunovi          #+#    #+#              #
#    Updated: 2017/01/27 16:41:31 by dpaunovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAG = -lmlx -framework OpenGL -framework AppKit
OPTION = -o $(NAME)
SRC = main.c checkmap.c

all: $(NAME)

$(NAME):
	@cd libft && make && make clean
	@gcc -L libft -lft $(OPTION) $(SRC) $(FLAG)
	@echo "\033[32mfdf created"

.PHONY: clean fclean re

clean:
	@rm -f $(NAME)
	@echo "\033[31mfdf deleted"

fclean:
	@cd libft && make fclean
	@rm -f $(NAME)
	@echo "\033[31mfdf deleted"

re: fclean all
