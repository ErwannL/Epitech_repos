##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## makefile
##

.PHONY: all clean fclean re

SRC		=	$(wildcard ./sources/*.c) \
			$(wildcard ./lib/*.c)

DEL 	=	$(wildcard ./sources/*.o) \
			$(wildcard ./lib/*.o)

OBJ		=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-I./include -g3

CC	=	gcc

all	: 	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

%.o: %.c
	$(CC) -o $@ -c $^

clean:
	rm -rf $(OBJ)
	rm -rf $(DEL)
	rm -rf .vscode
	rm -rf a.out

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
