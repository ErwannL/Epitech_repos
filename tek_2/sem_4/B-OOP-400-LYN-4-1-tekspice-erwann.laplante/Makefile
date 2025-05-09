##
## EPITECH PROJECT, 2023
## B-OOP-400-LYN-4-1-tekspice-erwann.laplante
## File description:
## Makefile
##

.PHONY: all clean fclean re tests_run

CC = g++

FLAG = -L. -I./include/ -g3

UNIT_FLAG = --coverage -lcriterion

NAME = nanotekspice

UNIT_NAME = unit-tests

LIB_NAME = libmy.a

LIB = -lmy

SRC	=	src/And.cpp			\
		src/Clock.cpp		\
		src/Component.cpp	\
		src/creation.cpp	\
		src/Error.cpp		\
		src/False.cpp		\
		src/Input.cpp		\
		src/My_4001.cpp		\
		src/My_4011.cpp		\
		src/My_4030.cpp		\
		src/My_4069.cpp		\
		src/My_4071.cpp		\
		src/My_4081.cpp		\
		src/Not.cpp			\
		src/Or.cpp			\
		src/Output.cpp		\
		src/Shell.cpp		\
		src/start.cpp		\
		src/True.cpp		\
		src/Xor.cpp			\

MAIN = src/main.cpp

UNIT_SRC = $(wildcard tests/*.cpp)

OBJ = $(SRC:.cpp=.o)

MAIN_OBJ = $(MAIN:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
	ar rc $(LIB_NAME) $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(MAIN_OBJ) $(LIB)

%.o: %.cpp
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(MAIN_OBJ)
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf $(LIB_NAME)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(UNIT_NAME)
	rm -rf a.out

re: fclean all

unit_test:
	$(CC) $(UNIT_FLAG) $(FLAG) -o $(UNIT_NAME) $(UNIT_SRC) $(SRC)
	./$(UNIT_NAME)

tests_run: unit_test clean
