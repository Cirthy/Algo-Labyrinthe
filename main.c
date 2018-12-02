#include	"labyrinthe.h"

int	main()//int argc, char const *argv[])
{
	labyrinthe L;
	L.lab_height = 0;
	L.lab_width = 0;
/*
	if(argc != 3)
	{
		printf("2 arg\n");
		return 0;
	}
	system("clear");
	printf("\n\n");
	

	//srand(time(NULL));
	//init_lab(&L, atoi(argv[1]), atoi(argv[2]));
*/
	
	menu(&L);

	//display(L);


	printf("\n\n");

	return 0;
}
