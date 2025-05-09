##
## EPITECH PROJECT, 2022
## B-CPE-200-LYN-2-1-dante-guilhem.vinet
## File description:
## Makefile
##

.PHONY: all clean fclean re generator solver

NAME	=	root

CC	=	gcc

all : $(NAME)

$(NAME): $(OBJ)
		make generator
		make solver

generator:
	make -C generator

solver:
	make -C solver

%.o: %.c
	$(CC) -o $@ -c $^

clean:
	make clean -C generator
	make clean -C solver
	rm -rf .vscode
	rm -rf a.out

fclean:
	make clean
	make fclean -C generator
	make fclean -C solver

re:
	make fclean
	make all
