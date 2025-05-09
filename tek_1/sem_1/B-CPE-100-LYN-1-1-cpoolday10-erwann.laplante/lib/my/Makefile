##
## EPITECH PROJECT, 2021
## Task 01 - Makefile
## File description:
## my_params_to_array
##

SRC	=	my_swap.c \
		my_strupcase.c \
		my_strstr.c \
		my_strncpy.c \
		my_strncmp.c \
		my_strncat.c \
		my_strlowcase.c	\
		my_strlen.c \
		my_strcpy.c \
		my_strcmp.c \
		my_strcat.c \
		my_strcapitalize.c \
		my_str_isupper.c \
		my_str_isprintable.c \
		my_str_isnum.c \
		my_str_islower.c \
		my_str_isalpha.c \
		my_sort_int_array.c \
		my_showstr.c \
		my_showmem.c \
		my_revstr.c \
		my_putstr.c \
		my_putchar.c \
		my_put_nbr.c \
		my_isneg.c \
		my_is_prime.c \
		my_getnbr.c \
		my_find_prime_sup.c \
		my_compute_square_root.c \
		my_compute_power_rec.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../
		cp my.h ../../include

clean:
		rm -f $(OBJ)
		rm -f ../../include/my.h
		rm -f ../$(NAME)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
