##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

.PHONY: all clean fclean re

CC         = g++
TARGET     = MyGKrellm

SRC        = $(shell find . -name "*.cpp") \
			$(wildcard graphical/*.cpp) \
			$(wildcard graphical/Interface/*.cpp)

OBJECTS    = $(patsubst %.cpp, %.o, $(SRC))

CFLAGS     +=
CFLAGS     += -Wall -Wextra
CFLAGS     += -c -I. -g3 -no-pie

LDFLAGS    =
LDLIBS     = -lsfml-graphics -lsfml-window -lsfml-system -lncurses

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "LD 	$@"
	@$(CC) -o $@ $^ $(LDLIBS)

%.o: %.cpp %.h
	@echo "CC 	$<"
	@$(CC) $< $(CFLAGS) -o $(LDLIBS) $@

main.o: main.cpp
	@echo "CC 	$<"
	@$(CC) $< $(CFLAGS) $(LDLIBS)

clean:
	@echo "removing target..."
	@rm -rf $(TARGET)

fclean: clean
	@echo "removing objects..."
	@rm -rf $(OBJECTS)

re: fclean all
