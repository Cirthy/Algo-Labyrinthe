NAME = labyrinthe

OUT = exec.out

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c gen_lab.c display_lab.c menu.c

all : $(NAME)			## Compile le projet

$(NAME) : 
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean :
	rm -f $(OUT) $(NAME)

re : fclean all			## Recompile le projet


coffee :			## Fait un café
	@echo -e '\n\n                         (\n                          )     (\n                   ___...(-------)-....___\n               .-""       )    (          ""-.\n         .-````|-._             )         _.-|\n        /  .--.|   `""---...........---""`   |\n       /  /    |                             |\n       |  |    |                             |\n        \  \   |                             |\n         `\ `\ |                             |\n           `\ `|                             |\n           _/ /\                             /\n          (__/  \                           /\n       _..---""` \                         /`""---.._\n    .-`           \                       /          `-.\n   :               `-.__             __.-`              : \n   :                  ) ""---...---"" (                 : \n    `._               `"--...___...--"`              _.`\n     \""--..__                              __..--""/\n       `._     """----.....______.....----"""     _.`\n          `""--..,,_____            _____,,..--""`\n                        `"""----"""`\t\tEnjoy drinking !\n'

help :
	@fgrep -h "##" $(MAKEFILE_LIST)  | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'


