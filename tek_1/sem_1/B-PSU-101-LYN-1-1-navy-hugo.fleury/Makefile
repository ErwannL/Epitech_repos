##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

.PHONY: all clean fclean re lib

CC         = gcc
TARGET     = navy

INST       = $(shell uname -m)
ARCH       = $(shell uname -s)

LSRC       = ./lib/
SRC        = $(wildcard src/*.c)

CFLAGS     +=
CFLAGS     += -Wall
CFLAGS     += -c -I./include/ -g3 -o

LDFLAGS    = -L./lib/
LDLIBS     = -lmy

OBJECTS    = $(SRC:.c=.o)

all: lib $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "LD 	$(TARGET)"
	@$(CC) -o $@ $(LDFLAGS) $^ $(LDLIBS)
	@echo "OK: built $(TARGET) for $(ARCH) ($(INST))."

src/%.o: src/%.c
	@echo "CC 	$<"
	@$(CC) $(CFLAGS) -c $< -o $@

lib:
	@make -C $(LSRC)

clean:
	@echo "[INFO]: removing libmy objects..."
	@rm -f $(OBJECTS)

fclean: clean
	@make -C $(LSRC) fclean
	@rm -f $(TARGET)

re: fclean all
