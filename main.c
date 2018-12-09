#include	"labyrinthe.h"

int	main()//int argc, char const *argv[])
{
	srand(time(NULL));

	

	labyrinthe L;
	L.lab_height = 0;
	L.lab_width = 0;

	/*

	path chemin;

	if(argc != 3)
	{
		printf("2 arg\n");
		return 0;
	}
	system("clear");
	printf("\n\n");
	

	init_lab(&L, atoi(argv[1]), atoi(argv[2]));

	

	display(L);
	printf("\n\n");

	chemin = profondeur_baptiste(&L);
	printf("\n\n");

	display_path(&chemin);
	*/

	menu(&L);



	return 0;
}
