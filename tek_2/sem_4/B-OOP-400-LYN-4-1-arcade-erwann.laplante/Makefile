##
## EPITECH PROJECT, 2023
## B-OOP-400-LYN-4-1-arcade-erwann.laplante
## File description:
## Makefile
##


.PHONY: all clean fclean re core games graphicals


CC = g++

CCFLAG = -fno-gnu-unique -g3 -fPIC  -I./src/core/ -I./src/graphicals/ -I./src/games/ -I./src/


NAME = arcade

NAME_NCURSES = lib/arcade_ncurses.so

NAME_SDL2 = lib/arcade_sdl2.so

NAME_SFML = lib/arcade_sfml.so

NAME_PACMAN = lib/arcade_nibbler.so

NAME_SNAKE = lib/arcade_snake.so


FLAG = -ldl

FLAG_NCURSES = -shared -fPIC -lncurses

FLAG_SDL2 = -shared -fPIC -lSDL2 -lSDL2_ttf -lSDL2_image

FLAG_SFML = -shared -fPIC -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio

FLAG_PACMAN = -shared -fPIC

FLAG_SNAKE = -shared -fPIC


SRC = $(wildcard src/core/*.cpp)

GRAPHICALS = $(wildcard src/graphicals/*.cpp)

GAMES = $(wildcard src/games/*.cpp)

SRC_NCURSES = $(GRAPHICALS) \
			  $(wildcard src/graphicals/NCurses/*.cpp)

SRC_SDL2 = $(GRAPHICALS) \
		   $(wildcard src/graphicals/SDL2/*.cpp)

SRC_PACMAN = $(wildcard src/games/Nibbler/*.cpp)

SRC_SFML = $(GRAPHICALS) \
		   $(wildcard src/graphicals/SFML/*.cpp)

SRC_SNAKE = $(GAMES) \
			$(wildcard src/games/Snake/*.cpp)


OBJ = $(SRC:.cpp=.o)

OBJ_NCURSES = $(SRC_NCURSES:.cpp=.o)

OBJ_SDL2 = $(SRC_SDL2:.cpp=.o)

OBJ_SFML = $(SRC_SFML:.cpp=.o)

OBJ_PACMAN = $(SRC_PACMAN:.cpp=.o)

OBJ_SNAKE = $(SRC_SNAKE:.cpp=.o)


all: core games graphicals

core: $(NAME)

games: $(NAME_PACMAN) $(NAME_SNAKE)

graphicals: $(NAME_NCURSES) $(NAME_SDL2) $(NAME_SFML)


$(NAME): $(OBJ)
		 $(CC) $(OBJ) -o $(NAME) $(FLAG)

$(NAME_NCURSES): $(OBJ_NCURSES)
		 		 $(CC) $(OBJ_NCURSES) -o $(NAME_NCURSES) $(FLAG_NCURSES)

$(NAME_SDL2): $(OBJ_SDL2)
		 	  $(CC) $(OBJ_SDL2) -o $(NAME_SDL2) $(FLAG_SDL2)

$(NAME_SFML): $(OBJ_SFML)
		 	  $(CC) $(OBJ_SFML) -o $(NAME_SFML) $(FLAG_SFML)

$(NAME_PACMAN): $(OBJ_PACMAN)
		 	    $(CC) $(OBJ_PACMAN) -o $(NAME_PACMAN) $(FLAG_PACMAN)

$(NAME_SNAKE): $(OBJ_SNAKE)
		 	   $(CC) $(OBJ_SNAKE) -o $(NAME_SNAKE) $(FLAG_SNAKE)


%.o: %.cpp
	$(CC) $(CCFLAG) -c $< -o $@


clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_NCURSES)
	rm -rf $(OBJ_SDL2)
	rm -rf $(OBJ_SFML)
	rm -rf $(OBJ_PACMAN)
	rm -rf $(OBJ_SNAKE)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_NCURSES)
	rm -rf $(NAME_SDL2)
	rm -rf $(NAME_SFML)
	rm -rf $(NAME_PACMAN)
	rm -rf $(NAME_SNAKE)
	rm -rf a.out

re: fclean all
