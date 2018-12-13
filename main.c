#include	"labyrinthe.h"

int	main()//int argc, char const *argv[])
{
	srand(time(NULL));
	init_displayer();
	labyrinthe L;
	
	L.height = 0;
	L.width = 0;
/*
	if(argc != 3)
	{
		printf("2 arg boloss\n");
		return 0;
	}
	system("clear");
	printf("\n\n");
	for(int i = 0 ; i < 1000 ; i++)
	{
		create_alea_lab(&L, atoi(argv[1]), atoi(argv[2]));
		pathfinding(&L, LARGEUR);
	}*/
	home_menu(&L);

	return 0;
}
