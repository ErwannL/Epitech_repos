##
## EPITECH PROJECT, 2022
## B-PSU-210-LYN-2-1-minishell2-erwann.laplante
## File description:
## Makefile
##

.PHONY: all clean fclean re

SRC		=	$(wildcard ./sources/*.c) \
			$(wildcard ./lib/*.c)

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
	rm -rf .vscode
	rm -rf a.out

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
