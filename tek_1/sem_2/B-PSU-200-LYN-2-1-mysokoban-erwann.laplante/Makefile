##
## EPITECH PROJECT, 2022
## B-PSU-200-LYN-2-1-mysokoban-erwann.laplante
## File description:
## Makefile
##

.PHONY: all clean fclean re

SRC		=	$(wildcard ./sources/*.c) \
			$(wildcard ./lib/*.c)

DEL 	=	$(wildcard ./sources/*.o) \
			$(wildcard ./lib/*.o)

OBJ		=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS	=	-I./include -g3 -lncurses

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
