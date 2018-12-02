NAME = labyrinthe

OUT = exec.out

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c gen_lab.c display_lab.c menu.c read_file.c save_file.c

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean :
	rm -f $(OUT) $(NAME)

re : fclean all


coffee :
	@echo -e '\n\n                         (\n                          )     (\n                   ___...(-------)-....___\n               .-""       )    (          ""-.\n         .-````|-._             )         _.-|\n        /  .--.|   `""---...........---""`   |\n       /  /    |                             |\n       |  |    |                             |\n        \  \   |                             |\n         `\ `\ |                             |\n           `\ `|                             |\n           _/ /\                             /\n          (__/  \                           /\n       _..---""` \                         /`""---.._\n    .-`           \                       /          `-.\n   :               `-.__             __.-`              : \n   :                  ) ""---...---"" (                 : \n    `._               `"--...___...--"`              _.`\n     \""--..__                              __..--""/\n       `._     """----.....______.....----"""     _.`\n          `""--..,,_____            _____,,..--""`\n                        `"""----"""`\t\tEnjoy drinking !\n
		