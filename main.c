#include	"labyrinth.h"

int	main()
{	
    struct 	winsize w;
    char 	ctemp;
    
    ioctl(0, TIOCGWINSZ, &w);
    if (w.ws_col<100 || w.ws_row<32)
    {
    	printf("Pour un affichage optimal du programme,\n");
    	printf("   nous vous conseillons une console de taille 100*32 minimum.\n\n");
    	printf("   Souhaitez vous quand même lancer le programme ? (y/n)");
		scanf("%1c",&ctemp);
		if (ctemp!='y')
			return 0 ;
	}

	srand(time(NULL));
	init_displayer();

	labyrinth L;
	L.height = 0;
	L.width = 0;

	home_menu(&L);

	return 0;
}
