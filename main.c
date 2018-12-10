#include	"labyrinthe.h"

int	main(int argc, char const *argv[])
{
	path path;

	srand(time(NULL));
	//init_displayer();

	

	labyrinthe L;
	L.lab_height = 0;
	L.lab_width = 0;

	

	//path chemin;

	if(argc != 3)
	{
		printf("2 arg boloss\n");
		return 0;
	}
	system("clear");
	printf("\n\n");
	

	create_alea_lab(&L, atoi(argv[1]), atoi(argv[2]));
	display_lab_V1(L);

	path = search_path_depth(&L);
	display_path(&path);
	/*
	display(L);
	printf("\n\n");

	chemin = profondeur_baptiste(&L);
	printf("\n\n");

	display_path(&chemin);
	*/

	//home_menu(&L);



	return 0;
}
