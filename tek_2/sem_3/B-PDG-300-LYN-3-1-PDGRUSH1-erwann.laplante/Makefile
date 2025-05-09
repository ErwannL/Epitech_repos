##
## EPITECH PROJECT, 2023
## B-PDG-300-LYN-3-1-PDGRUSH1-erwann.laplante
## File description:
## Makefile
##

.PHONY : all, clean, fclean, re

NAME = pushswap_checker

SRC =   $(wildcard *.hs)

OOBJ =   $(SRC:.hs=.o)

HIOBJ =   $(SRC:.hs=.hi)

CC = ghc

all: $(NAME)

$(NAME): $(OOBJ)
	$(CC) -o $(NAME) $(OOBJ)

%.o: %.hs
	$(CC) -c $< -o $@

%.hi: %.hs
	$(CC) -c $< -o $@

clean:
	rm -rf $(OOBJ)
	rm -rf $(HIOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
