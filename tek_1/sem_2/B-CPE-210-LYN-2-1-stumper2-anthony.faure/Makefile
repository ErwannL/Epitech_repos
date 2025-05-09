##
## EPITECH PROJECT, 2022
## B-CPE-210-LYN-2-1-stumper2-anthony.faure
## File description:
## Makefile
##

SRC		=	$(wildcard ./src/*.c) \
			$(wildcard ./lib/*.c) \

OBJ		=	$(SRC:.c=.o)

NAME	=	connect4

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
