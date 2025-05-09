##
## EPITECH PROJECT, 2021
## Task 01 - my_params_to_list
## File description:
## description
##

SRC	=	my_putchar.c \
		my_putstr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
