##
## EPITECH PROJECT, 2023
## B-ASM-400-LYN-4-1-asmminilibc-erwann.laplante
## File description:
## Makefile
##

.PHONY: all clean fclean re test tests_run

CC = ld

FLAG = -fpic -shared

NAME = libasm.so

SRC	= src/strlen.asm      \
	  src/strchr.asm      \
	  src/strrchr.asm     \
	  src/memset.asm      \
	  src/memcpy.asm      \
	  src/strcmp.asm      \
	  src/memmove.asm     \
	  src/strncmp.asm     \
	  src/strcasecmp.asm  \
	  src/strstr.asm      \
	  src/strpbrk.asm     \
	  src/strcspn.asm     \
	  src/strncasecmp.asm \
	  src/strspn.asm      \
	  src/index.asm       \
	  src/rindex.asm      \

C_TST = tests/c_tests/src/color.c 			 \
		tests/c_tests/src/main.c  			 \
	    tests/c_tests/src/test_memmove.c 	 \
	    tests/c_tests/src/test_strcasecmp.c  \
	    tests/c_tests/src/test_strcmp.c 	 \
	    tests/c_tests/src/test_strlen.c 	 \
	    tests/c_tests/src/test_strpbrk.c 	 \
	    tests/c_tests/src/test_strstr.c		 \
	    tests/c_tests/src/help.c   			 \
	    tests/c_tests/src/test_memcpy.c  	 \
	    tests/c_tests/src/test_memset.c   	 \
	    tests/c_tests/src/test_strchr.c      \
	    tests/c_tests/src/test_strcspn.c  	 \
	    tests/c_tests/src/test_strncmp.c  	 \
	    tests/c_tests/src/test_strrchr.c     \
	    tests/c_tests/src/test_strncasecmp.c \
	    tests/c_tests/src/test_strspn.c  	 \
	    tests/c_tests/src/test_index.c       \
	    tests/c_tests/src/test_rindex.c      \
	    tests/c_tests/src/args.c             \

U_TST = tests/unit_tests/src/test_strlen.c      \
		tests/unit_tests/src/test_strchr.c      \
		tests/unit_tests/src/test_strrchr.c     \
		tests/unit_tests/src/test_memset.c      \
		tests/unit_tests/src/test_memcpy.c      \
		tests/unit_tests/src/test_strcmp.c      \
		tests/unit_tests/src/test_memmove.c     \
		tests/unit_tests/src/test_strncmp.c     \
		tests/unit_tests/src/test_strcasecmp.c  \
		tests/unit_tests/src/test_strstr.c      \
		tests/unit_tests/src/test_strpbrk.c     \
		tests/unit_tests/src/test_strcspn.c     \
		tests/unit_tests/src/test_strncasecmp.c \
		tests/unit_tests/src/test_strspn.c      \
		tests/unit_tests/src/test_index.c       \
		tests/unit_tests/src/test_rindex.c      \

OBJ	 = $(SRC:.asm=.o)

all: $(NAME)

$(NAME): $(OBJ)
	 $(CC) $(FLAG) -o $(NAME) $(OBJ)

%.o: %.asm
	nasm -f elf64 $< -o $@

test: all
	gcc $(C_TST) -o my_test

tests_run: all
	gcc -o unit-tests $(U_TST) --coverage -lcriterion
	./unit-tests

clean:
	rm -rf $(OBJ)
	rm -rf *.gcno
	rm -rf *.gcda

fclean: clean
	rm -rf $(NAME)
	rm -rf my_test
	rm -rf unit-tests
	rm -rf a.out

re:	fclean all
