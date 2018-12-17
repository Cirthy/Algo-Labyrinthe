#include	"labyrinth.h"

#define 	NOMBRE_LAB				1000
#define		TAILLE_LAB_CARRE		4000
#define		TYPE 					'r'		// 'i'tératif
											// 'r'écursif


int	main()
{

	labyrinth L;
	path p;
	srand(time(NULL));

	printf("génération et algo %c\nnombre de tests : %d\nlabyrinthe %dx%d\n",TYPE,NOMBRE_LAB,TAILLE_LAB_CARRE,TAILLE_LAB_CARRE);

	for(int i=0 ; i<NOMBRE_LAB ; i++)
	{
		printf("test %3d ->",i);
		fflush(stdout);

		create_alea_lab(&L, TAILLE_LAB_CARRE, TAILLE_LAB_CARRE);

		printf(" généré ->");
		fflush(stdout);

		if (TYPE == 'r')
			p = pathfinding(&L, LARGEUR);
		else
			p = BFS(L);

		printf(" longeur %4d ->", p.length);
		fflush(stdout);

		if (p.length != -1)
			free(p.cells);
		for(int j = 0 ; j < L.height ; j++)
			free(L.grid[j]);
		free(L.grid);

		printf(" free\n");
	}

	return 0;
}
