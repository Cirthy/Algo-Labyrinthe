#include	"labyrinthe.h"

int	main(int argc, char const *argv[])
{
	path path;

	srand(time(NULL));
	//init_displayer();


	

	labyrinthe L;
	L.height = 0;
	L.width = 0;

	if(argc != 3)
	{
		printf("2 arg boloss\n");
		return 0;
	}
	system("clear");
	printf("\n\n");
	

	create_alea_lab(&L, atoi(argv[1]), atoi(argv[2]));
	display_lab_V1(L);
	path = DFS(&L);
	display_path(&path);

//	home_menu(&L);



	return 0;
}
