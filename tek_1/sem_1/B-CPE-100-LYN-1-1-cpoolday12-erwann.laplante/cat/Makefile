##
## EPITECH PROJECT, 2021
## Task 01 - my_params_to_list
## File description:
## description
##

SRC	=	cat.c

OBJ	=	$(SRC:.c=.o)

NAME	=	cat

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(SRC) -o $(NAME) -L ../lib/my -lmy

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
