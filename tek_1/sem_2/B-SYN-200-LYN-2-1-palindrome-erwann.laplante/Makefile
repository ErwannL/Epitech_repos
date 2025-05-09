##
## EPITECH PROJECT, 2022
## private_palindrome
## File description:
## Makefile
##

.PHONY : all, clean, fclean, re

NAME = palindrome

LIB_NAME = libmy.a

SRC =	src/main.c \
		src/parsing.c \
		src/struct.c \
		src/help.c

SRC_LIB =	lib/convert.c \
			lib/utilities.c \
			lib/string_free.c

OBJ =	$(SRC:.c=.o)

OBJ_LIB =	$(SRC_LIB:.c=.o)

LIB = -lmy

CC = gcc

FLAGS = -L. -I./include/ -g3

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIB)
	ar rc $(LIB_NAME) $(OBJ_LIB)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIB)

src/%.o: src/%.c
	$(CC) $(FLAGS) -c $< -o $@

lib/%.o: lib/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_LIB)
	rm -rf a.out

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIB_NAME)

re: fclean all
