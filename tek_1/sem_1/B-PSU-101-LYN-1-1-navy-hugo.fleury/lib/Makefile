##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

.PHONY: all clean fclean re

CC 		= gcc
TARGET 	= libmy.a

ARCH 	= $(shell arch)
UNAME 	= $(shell uname -s)
SRC 	= $(wildcard ./*.c)

CFLAGS 	= -I. -Wall -g3

OBJECTS = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "AR 	$(TARGET)"
	@ar rc $(TARGET) $^
	@ranlib $(TARGET)
	@cp $(TARGET) ../
	@cp my.h ../include/
	@echo "OK: built $(TARGET) for $(ARCH) ($(UNAME))."

%.o: %.c
	@echo "CC 	$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(TARGET)
	@rm -f ../$(TARGET)

re: fclean all
