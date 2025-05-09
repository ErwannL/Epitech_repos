##
## EPITECH PROJECT, 2022
## B-CPE-210-LYN-2-1-stumper3-anthony.faure
## File description:
## Makefile
##

.PHONY: all clean fclean re

SRC		=	$(wildcard ./src/*.c) \
			$(wildcard ./lib/*.c) \

OBJ		=	$(SRC:.c=.o)

NAME	=	crocus

CFLAGS	=	-I./include -g3

all	: 	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

%.o: %.c
	$(CC) -o $@ -c $^

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
