##
## EPITECH PROJECT, 2021
## Task 01 - my_params_to_list
## File description:
## description
##

SRC	=	btree_create_node.c \
		btree_apply_suffix.c \
		btree_apply_prefix.c \
		btree_apply_infix.c \
		btree_insert_data.c \
		btree_search_item.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libbtree.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
