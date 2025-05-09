##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## makefile
##

SRC		=	disp_stdarg.c \
			sum_numbers.c \
			sum_strings_length.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I./include -g3

all	: 	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	mkdir .file_o
	mv $(OBJ) .file_o

clean:
	rm -f -r .file_o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

unit_tests :

run_tests :
