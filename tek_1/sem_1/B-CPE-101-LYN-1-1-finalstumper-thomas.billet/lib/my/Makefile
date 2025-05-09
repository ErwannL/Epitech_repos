##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC        =    $(shell find . -type f -name "*.c")

OBJ        =    $(SRC:.c=.o)

NAME    =    libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mv $(NAME) ../

clean:
	rm -f $(OBJ)
	rm -f vgcore*

fclean:    clean
		rm -f ../$(NAME)

re:	fclean all