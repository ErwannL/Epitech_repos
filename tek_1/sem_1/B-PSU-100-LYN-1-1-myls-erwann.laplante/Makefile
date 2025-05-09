##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## makefile
##

SRC		=	$(wildcard ./source/*.c) \
			$(wildcard ./lib/*.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	my_ls

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
	rm -f $(OBJ)
	rm -rf .vscode

re:	fclean all
