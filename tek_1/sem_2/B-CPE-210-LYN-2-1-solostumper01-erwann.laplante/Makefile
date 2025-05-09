##
## EPITECH PROJECT, 2022
## B-CPE-210-LYN-2-1-solostumper01-erwann.laplante
## File description:
## Makefile
##

.PHONY: all clean fclean re

SRC		=	./src/main.c \
			./lib/my_putchar.c \
			./lib/my_putstr.c

OBJ		=	$(SRC:.c=.o)

NAME	=	clean_str

CFLAGS	=	-I./include -g3

CC	=	gcc

all	: 	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

%.o: %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
