##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

.PHONY: all clean fclean re

CC         = gcc
TARGET     = lem_in

INST       = $(shell uname -m)
ARCH       = $(shell uname -s)

SRC        = $(wildcard src/*.c) \
			$(wildcard lib/*.c)

CFLAGS     +=
CFLAGS     += -Wall
CFLAGS     += -c -I./include/ -g3 -o

LDFLAGS    =
LDLIBS     =

OBJECTS    = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "LD 	$(TARGET)"
	@$(CC) -o $@ $(LDFLAGS) $^ $(LDLIBS)
	@echo "OK: built $(TARGET) for $(ARCH) ($(INST))."

src/%.o: src/%.c
	@echo "CC 	$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(TARGET)

re: fclean all
