NAME = labyrinthe

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = generator.c display.c menu.c loadsave.c management.c pathfinding.c

all : $(NAME)			## Compile le projet

$(NAME) : 
	$(CC) $(CFLAGS) main.c $(SRCS) -o $(NAME)

fclean :
	rm -f $(NAME)

re : fclean all			## Recompile le projet


coffee :			## Fait un café
	@echo -e '\n\n                         (\n                          )     (\n                   ___...(-------)-....___\n               .-""       )    (          ""-.\n         .-````|-._             )         _.-|\n        /  .--.|   `""---...........---""`   |\n       /  /    |                             |\n       |  |    |                             |\n        \  \   |                             |\n         `\ `\ |                             |\n           `\ `|                             |\n           _/ /\                             /\n          (__/  \                           /\n       _..---""` \                         /`""---.._\n    .-`           \                       /          `-.\n   :               `-.__             __.-`              : \n   :                  ) ""---...---"" (                 : \n    `._               `"--...___...--"`              _.`\n     \""--..__                              __..--""/\n       `._     """----.....______.....----"""     _.`\n          `""--..,,_____            _____,,..--""`\n                        `"""----"""`\t\tEnjoy drinking !\n'

help :
	@fgrep -h "##" $(MAKEFILE_LIST)  | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'

stats :
	$(CC) $(CFLAGS) main_stats.c $(SRCS) -o $(NAME)


