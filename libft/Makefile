# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 18:19:19 by dpaunovi          #+#    #+#              #
#    Updated: 2017/02/01 16:50:03 by dpaunovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h get_next_line.h
FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
SRC = $(addprefix ft_, putchar.c putstr.c strcmp.c \
	strlen.c swap.c putnbr.c memset.c bzero.c \
	memcpy.c memccpy.c memmove.c memchr.c memcmp.c \
	strdup.c strcpy.c strncpy.c strcat.c strncat.c \
	strlcat.c strchr.c strrchr.c strstr.c strnstr.c \
	atoi.c strcmp.c strncmp.c isalpha.c isdigit.c \
	isalnum.c isascii.c isprint.c toupper.c tolower.c \
	memalloc.c memdel.c strnew.c strdel.c strclr.c \
	striter.c striteri.c strmap.c strmapi.c strequ.c \
	strnequ.c strsub.c strjoin.c strtrim.c strsplit.c \
	itoa.c putendl.c putchar_fd.c putstr_fd.c putnbr_fd.c \
	putendl_fd.c strcchr.c putnbr_endl.c strspn.c strcspn.c \
	charcmp.c stpcpy.c lstnew.c lstdelone.c lstdel.c \
	lstadd.c lstiter.c lstmap.c iswhitespace.c \
	put_ntabi.c put_ntabs.c put_tabi.c put_tabs.c \
	tabilen.c tabslen.c replace_char.c strndup.c lstaddend.c \
	lstlen.c) get_next_line.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	@gcc $(FLAG) $(OPTION) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[32mlibft created"

clean:
	@rm -f $(OBJ)
	@echo "\033[36mFiles .o deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mlibft deleted"

re: fclean all
