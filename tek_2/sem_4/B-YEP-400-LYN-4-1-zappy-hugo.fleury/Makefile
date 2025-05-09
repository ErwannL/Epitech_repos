##
## EPITECH PROJECT, 2023
## B-YEP-400-LYN-4-1-zappy-hugo.fleury
## File description:
## Makefile
##

.PHONY: all zappy_ai zappy_gui zappy_server clean fclean re

all: zappy_ai zappy_gui zappy_server

zappy_ai:
	$(MAKE) -C ai

zappy_gui:
	$(MAKE) -C gui

zappy_server:
	$(MAKE) -C server

clean:
	$(MAKE) -C ai clean
	$(MAKE) -C gui clean
	$(MAKE) -C server clean

fclean: clean
	$(MAKE) -C ai fclean
	$(MAKE) -C gui fclean
	$(MAKE) -C server fclean

re: fclean all
