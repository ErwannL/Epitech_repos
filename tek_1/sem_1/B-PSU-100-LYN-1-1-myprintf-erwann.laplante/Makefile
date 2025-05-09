##
## EPITECH PROJECT, 2021
## B-PSU-100-LYN-1-1-myprintf-erwann.laplante
## File description:
## Makefile
##

.PHONY: all clean fclean re test

NAME 	 = libmy.a
SRC 	 = $(wildcard source/*.c)
SRC2 	 = $(wildcard tests/*.c)
FLAGS  = -L./ -g3 -lcriterion
LIB    = -lmy
OBJ  = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	mkdir .file_o
	mv $(OBJ) .file_o

test: re unit_tests

unit_tests: $(OBJ2)
	gcc -o $@ $(FLAGS) $^ $(LIB)
	mv $(OBJ2) .file_o
	./unit_tests

clean:
	rm -f $(OBJ) $(OBJ2)

fclean: clean
	rm -rf .file_o
	rm -rf unit_tests
	rm -rf vgcore.*
	rm -f $(NAME)
	rm -rf .vscode

re: fclean all
