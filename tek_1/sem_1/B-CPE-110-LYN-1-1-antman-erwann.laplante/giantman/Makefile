##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## makefile
##

.PHONY: all clean fclean re

grey	=	/bin/echo -e "\x1b[30m$1\x1b[0m"
red		=	/bin/echo -e "\x1b[31m$1\x1b[0m"
green	=	/bin/echo -e "\x1b[32m$1\x1b[0m"
yellow	=	/bin/echo -e "\x1b[33m$1\x1b[0m"
blue	=	/bin/echo -e "\x1b[34m$1\x1b[0m"
purple	=	/bin/echo -e "\x1b[35m$1\x1b[0m"
cyan	=	/bin/echo -e "\x1b[36m$1\x1b[0m"
white	=	/bin/echo -e "\x1b[37m$1\x1b[0m"

SRC		=	$(wildcard ./sources/*.c) \
			$(wildcard ./lib/*.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	giantman

CFLAGS	=	-I./include -g3

CC	=	gcc

all	: 	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

%.o: %.c
	$(CC) -o $@ -c $^

clean:
	rm -rf $(OBJ)
	rm -rf .vscode
	rm -rf a.out

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
