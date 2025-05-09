##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

.PHONY: all clean fclean re

CC         = gcc
TARGET     = 42sh

INST       = $(shell uname -m)
ARCH       = $(shell uname -s)

SRC        = $(wildcard src/*.c)
ISRC       = $(wildcard src/internal/*.c)

CFLAGS     +=
CFLAGS     += -Wall
CFLAGS     += -c -I./include/ -g3 -fno-builtin-memset -o

LDFLAGS    =
LDLIBS     =

OBJECTS    = $(SRC:.c=.o)
IOBJECTS   = $(ISRC:.c=.o)

all: $(TARGET)

$(TARGET): $(IOBJECTS) $(OBJECTS)
	@echo "LD 	$(TARGET)"
	@$(CC) -o $@ $(LDFLAGS) $^ $(LDLIBS)
	@echo "OK: built $(TARGET) for $(ARCH) ($(INST))."

src/%.o: src/%.c
	@echo "CC 	$<"
	@$(CC) $(CFLAGS) -c $< -o $@

src/internal/%.o: src/internal/%.c
	@echo "CC 	$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)
	@rm -f $(IOBJECTS)

fclean: clean
	@rm -f $(TARGET)

re: fclean all
