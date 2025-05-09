##
## EPITECH PROJECT, 2022
## B-CPE-110-LYN-1-1-antman-erwann.laplante
## File description:
## Makefile
##

.PHONY: all clean fclean re

grey	=	/bin/echo -e "\x1b[30m$1\x1b[0m"
red		=	/bin/echo -e "\x1b[31m$1\x1b[0m"
green	=	/bin/echo -e "\x1b[32m$1\x1b[0m"
yellow	=	/bin/echo -e "\x1b[33m$1\x1b[0m"
blue	=	/bin/echo -e "\x1b[34m$1\x1b[0m"
purple	=	/bin/echo -e "\x1b[35m$1\x1b[0m"
cyan	=	/bin/echo -e "\x1b[36m$1\x1b[0m"
white	=	/bin/echo -e "\x1b[37m$1\x1b[0m"

NAME	=	root

CC	=	gcc

all : $(NAME)

$(NAME): $(OBJ)
	@$(call green,"~~~~~~~~~~~~~~~~~~~~START COMPILING~~~~~~~~~~~~~~~~~~~~")
	@$(call blue,"----------Compiling Antman----------")
	make -C antman
	@$(call blue,"----------End Antman----------")
	@$(call blue,"----------Compiling Giantman----------")
	make -C giantman
	@$(call blue,"----------End Giantman----------")
	@$(call green,"~~~~~~~~~~~~~~~~~~~~END COMPILING~~~~~~~~~~~~~~~~~~~~")

%.o: %.c
	$(CC) -o $@ -c $^

clean:
	@$(call green,"~~~~~~~~~~~~~~~~~~~~START CLEANING~~~~~~~~~~~~~~~~~~~~")
	@$(call blue,"----------Cleaning Antman----------")
	make clean -C antman
	@$(call blue,"----------End Antman----------")
	@$(call blue,"----------Cleaning Giantman----------")
	make clean -C giantman
	@$(call blue,"----------End Giantman----------")
	@$(call blue,"----------Cleaning Repository----------")
	rm -rf .vscode
	rm -rf a.out
	@$(call blue,"----------End Repository----------")
	@$(call green,"~~~~~~~~~~~~~~~~~~~~END CLEANING~~~~~~~~~~~~~~~~~~~~")

fclean:
	make clean
	@$(call green,"~~~~~~~~~~~~~~~~~~~~START FCLEANING~~~~~~~~~~~~~~~~~~~~")
	@$(call blue,"----------Fcleaning Antman----------")
	make fclean -C antman
	@$(call blue,"----------End Antman----------")
	@$(call blue,"----------Fcleaning Giantman----------")
	make fclean -C giantman
	@$(call blue,"----------End Giantman----------")
	@$(call green,"~~~~~~~~~~~~~~~~~~~~END FCLEANING~~~~~~~~~~~~~~~~~~~~")

re:
	@$(call red,"__________________________START__________________________")
	make fclean
	make all
	@$(call red,"__________________________END__________________________")
