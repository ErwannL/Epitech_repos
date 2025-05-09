##
## EPITECH PROJECT, 2021
## Task 01 - my_params_to_list
## File description:
## description
##

SRC	=	my_putchar.c \
		my_putstr.c \
		my_put_nbr.c \
		my_strdup.c \
		my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp my.h ../../include

clean:
		rm -f $(OBJ)
		rm -f ../../include/my.h

fclean:	clean
		rm -f $(NAME)

re:	fclean all
