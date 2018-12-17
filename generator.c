#include	"labyrinthe.h"


void 	create_alea_lab(labyrinthe *L, int height, int width)
{
	create_empty_lab(L, height, width);
	L->entrance = pos(rand() % L->width, rand() % L->height);
	L->exit     = pos(rand() % L->width, rand() % L->height);
	init_wall(L);
}


void	create_empty_lab(labyrinthe *L, int height, int width) // Create an empty lab with walls on the sides
{
	int		i;

	L->grid = (unsigned short **)malloc(sizeof(unsigned short *) * height);
	for(i = 0 ; i < height ; i++)
		(L->grid)[i] = (unsigned short *)calloc(sizeof(unsigned short), width);
	L->height = height;
	L->width = width;
	L->entrance = pos(0, 0);
	L->exit = pos(0, 0);
	L->cursor = pos(0, 0);

	for(i = 0 ; i < L->height ; i++)
	{
		L->grid[i][0] += LW; 				//left wall
		L->grid[i][L->width-1] += RW; 	//right wall
	}
	for(i = 0 ; i < L->width ; i++)
	{
		L->grid[0][i] += TW; 				//top wall
		L->grid[L->height-1][i] += BW; 	//bottom wall
	}
}


void	init_wall(labyrinthe *L) // Set random walls (with a probability of 1 / WALL_PROB)
{
	for(int i = 0 ; i < L->height ; i++)
		for(int j = 0 ; j < L->width ; j++)
		{
			L->grid[i][j] += (i == 0) ? 0 : bottom_wall(L->grid[i - 1][j]) * TW;//top wall
			L->grid[i][j] += (j == 0) ? 0 : right_wall(L->grid[i][j - 1]) * LW;//left wall
			L->grid[i][j] += (i == L->height - 1) ? 0 : !(rand() % WALL_PROB) * BW;//bottom wall
			L->grid[i][j] += (j == L->width - 1) ? 0 : !(rand() % WALL_PROB) * RW;//right wall
		}
}
