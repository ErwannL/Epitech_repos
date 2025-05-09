##
## EPITECH PROJECT, 2021
## EvalExpr
## File description:
## description
##

SRC	=   $(wildcard ./*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	eval_expr

CFLAGS	=	-g3

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
