##
## EPITECH PROJECT, 2022
## B-MUL-200-LYN-2-1-mydefender-erwann.laplante
## File description:
## Makefile
##

SRC		=	$(wildcard ./source/*.c) \
			$(wildcard ./lib/*.c) \

OBJ		=	$(SRC:.c=.o)

NAME	=	my_defender

CFLAGS	=	-I./include -g3 -lcsfml-graphics -lcsfml-audio -lcsfml-system
CFLAGS2 =	-lcsfml-window

all	: 	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CFLAGS2)

%.o: %.c
	$(CC) -o $@ -c $^

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
