##
## EPITECH PROJECT, 2021
## Task 01 - my_params_to_list
## File description:
## description
##

SRC	=   $(wildcard ./*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	infin_add

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) -g3 $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
