#include	"labyrinthe.h"

int	main()//int argc, char const *argv[])
{

/*	labyrinthe L;

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
		//pathfinding(&L, LARGEUR);
		BFS(L);
	}*/

	
    struct 	winsize w;
    char 	ctemp;
    
    ioctl(0, TIOCGWINSZ, &w);
    if (w.ws_col<100 || w.ws_row<32)
    {
    	printf("Pour un affichage optimal du programme,\n");
    	printf("   nous vous conseillons un console de taille 100*32 minimum.\n\n");
    	printf("   Souhaitez vous quand même lancer le programme ? (y/n)");
		scanf("%1c",&ctemp);
		if (ctemp!='y')
			return 0 ;
	}


	srand(time(NULL));
	init_displayer();

	labyrinthe L;
	L.height = 0;
	L.width = 0;

	home_menu(&L);

	return 0;
}
