##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC = $(shell find ./source/ -type f -name "*.c")

OBJ = $(SRC:.c=.o)

NAME = rush3

CFLAGS = -g3 -g

all:	$(OBJ)
	make -C ./lib/my
	gcc $(OBJ) -L ./lib/ -l my  -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean:    clean
		rm -f $(NAME)
		rm -f vgcore*
		make fclean -C ./lib/my

re: fclean all
