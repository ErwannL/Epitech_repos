##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

.PHONY: all clean fclean re

CC         = gcc
TARGET     = my_rpg

INST       = $(shell uname -m)
ARCH       = $(shell uname -s)

SRC        = $(wildcard src/*.c) \
			 $(wildcard lib/*.c) \
			 $(wildcard src/game_creation/*.c) \
			 $(wildcard src/my_lib_csfml/*.c)

CFLAGS     +=
CFLAGS     += -Wall -Wno-deprecated-declarations
CFLAGS     += -c -I./include/ -g3 -o

LDFLAGS    =
LDLIBS     = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

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
	@echo "[INFO]: removing objects..."
	@rm -f $(OBJECTS)

fclean: clean
	@echo "[INFO]: removing target..."
	@rm -f $(TARGET)

re: fclean all
