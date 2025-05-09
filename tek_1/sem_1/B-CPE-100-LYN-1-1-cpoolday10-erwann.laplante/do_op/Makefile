##
## EPITECH PROJECT, 2021
## Task 02 - do-op
## File description:
## my_params_to_array
##

SRC	=	do_op.c

OBJ	=	$(SRC:.c=.o)

NAME	=	test

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o do-op $(SRC) -L../lib/ -lmy

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f do-op

re:	fclean all
