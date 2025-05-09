##
## EPITECH PROJECT, 2023
## B-PDG-300-LYN-3-1-PDGD04am-erwann.laplante
## File description:
## Makefile
##

.PHONY : all, clean, fclean, re

NAME = z

SRC =	$(wildcard *.c)

OBJ =	$(SRC:.c=.o)

FLAGS = -L. -I./include/ -g3  -std=gnu17 -Wall -Wextra

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ)

src/%.o: src/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf a.out

fclean: clean
	rm -rf $(NAME)

re: fclean all
