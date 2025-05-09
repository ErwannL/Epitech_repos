##
## EPITECH PROJECT, 2023
## B-FUN-400-LYN-4-1-wolfram-erwann.laplante
## File description:
## Makefile
##

.PHONY: all clean fclean re tests_run

NAME = wolfram
STACK_PATH := $(shell stack path --local-install-root)

all:
	stack build
	cp $(STACK_PATH)/bin/$(NAME)-exe ./$(NAME)

clean:
	stack clean

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

re: fclean all
