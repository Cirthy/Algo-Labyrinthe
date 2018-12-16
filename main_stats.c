#include	"labyrinthe.h"

int	main()
{

	labyrinthe L;
	for(int i=0 ; i<1000 ; i++)
	{
		create_alea_lab(&L, 1000, 1000);
		pathfinding(&L, LARGEUR);
		for(int j = 0 ; j < L.height ; j++)
			free(L.grid[j]);
		free(L.grid);
	}

	return 0;
}
