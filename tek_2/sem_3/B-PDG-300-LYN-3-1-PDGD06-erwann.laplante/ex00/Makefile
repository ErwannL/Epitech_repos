##
## EPITECH PROJECT, 2023
## B-PDG-300-LYN-3-1-PDGD06-erwann.laplante
## File description:
## Makefile
##

.PHONY : all, clean, fclean, re

NAME = Z

SRC =	$(wildcard *.cpp)

OBJ =	$(SRC:.cpp=.o)

FLAGS = -std=c++20 -Wall -Wextra -Werror

CC = g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf a.out

fclean: clean
	rm -rf $(NAME)

re: fclean all
