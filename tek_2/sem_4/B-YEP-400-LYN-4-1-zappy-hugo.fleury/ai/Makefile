##
## EPITECH PROJECT, 2023
## B-YEP-400-LYN-4-1-zappy-hugo.fleury
## File description:
## Makefile
##

.PHONY: all clean fclean re

SRC = $(wildcard src/*.py)

NAME = zappy_ai

INCLUDE = include/*.py

all: $(NAME)

#pip install pyinstaller
$(NAME):
	pyinstaller --onefile --name $(NAME) --distpath ../ --add-data "$(INCLUDE):." $(SRC)

clean:
	rm -rf a.out
	rm -rf build
	rm -rf *.spec

fclean:	clean
	rm -rf ../$(NAME)

re:	fclean all
