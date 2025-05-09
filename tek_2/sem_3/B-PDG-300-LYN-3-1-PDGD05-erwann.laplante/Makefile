##
## EPITECH PROJECT, 2023
## B-PDG-300-LYN-3-1-PDGD05-erwann.laplante
## File description:
## Makefile
##

.PHONY : all, clean, fclean, re

LIB_NAME = libstring.a

SRC_LIB =	append.c\
			assign.c\
			at.c\
			c_str.c\
			clear.c\
			compare.c\
			copy.c\
			destroy.c\
			empty.c\
			find.c\
			init.c\
			lenght.c\
			strcat.c

OBJ_LIB =	$(SRC_LIB:.c=.o)

CC = gcc

FLAGS = -L./ -I./ -g3 -std=gnu17 -Wall -Wextra

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_LIB)
	ar rc $(LIB_NAME) $(OBJ_LIB)

lib/%.o: lib/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_LIB)

fclean: clean
	rm -rf $(LIB_NAME)
	rm -rf a.out

re: fclean all
