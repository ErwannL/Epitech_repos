##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## makefile
##

SRC		=	$(wildcard ./source/*.c) \
			$(wildcard ./lib/*.c) \
			$(wildcard ./source/letters/*.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	my_runner

CFLAGS	=	-I./include -g3 -lcsfml-graphics -lcsfml-audio -lcsfml-system
CFLAGS2 =	-lcsfml-window

all	: 	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CFLAGS2)
	mkdir .file_o
	mv $(OBJ) .file_o

clean:
	rm -f -r .file_o

fclean:	clean
	rm -f $(NAME)
	rm -f $(OBJ)
	rm -rf .vscode
	rm -rf a.out

re:	fclean all
