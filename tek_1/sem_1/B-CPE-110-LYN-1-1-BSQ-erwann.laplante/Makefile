##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## makefile
##

.PHONY: all clean fclean re

SRC		=	$(wildcard ./source/*.c) \
			$(wildcard ./lib/*.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	=	-I./include -g3

all	: 	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	mkdir .file_o
	mv $(OBJ) .file_o

clean:
	rm -f -r .file_o

fclean:	clean
	rm -f $(NAME)
	rm -r -f .vscode
	rm -r -f vgcore.*

re:	fclean all
