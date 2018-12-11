#include	"labyrinthe.h"


void	create_empty_lab(labyrinthe *L, int height, int width)
{
	//initialisation
	int		i;
	int		j;

	L->grid = (unsigned short **)malloc(sizeof(unsigned short *) * height);
	for(i = 0 ; i < height ; i++)
		(L->grid)[i] = (unsigned short *)calloc(sizeof(unsigned short), width);
	L->height = height;
	L->width = width;
	L->entrance.x=0;
	L->entrance.y=0;
	L->exit.x=0;
	L->exit.y=0;
	L->cursor.x=0;
	L->cursor.y=0;

	for(i = 0 ; i < L->height ; i++)
	{
		L->grid[i][0] += LW; 				//left wall
		L->grid[i][L->width-1] += RW; 	//right wall
	}
	for(j = 0 ; j < L->width ; j++)
	{
		L->grid[0][j] += TW; 				//top wall
		L->grid[L->height-1][j] += BW; 	//bottom wall
	}
}


void 	create_alea_lab(labyrinthe *L, int height, int width)
{
	create_empty_lab(L, height, width);
	srand(time(NULL));
	L->entrance.x = rand() % L->width;
	L->entrance.y = rand() % L->height;
	L->exit.x     = rand() % L->width;
	L->exit.y     = rand() % L->height;
	init_wall(L);
}

/*
void	init_lab(labyrinthe *L, int height, int width)
{
	int			i;
	position	temp;

	L->grid = (unsigned short **)malloc(sizeof(unsigned short *) * height);
	for(i = 0 ; i < height ; i++)
		(L->grid)[i] = (unsigned short *)calloc(sizeof(unsigned short), width);
	L->height = height;
	L->width = width;
	temp.x = rand() % width;
	temp.y = rand() % height;
	L->entrance = temp;
	temp.x = rand() % width;
	temp.y = rand() % height;
	L->exit = temp;
	L->cursor.x = 0;
	L->cursor.y = 0;
	init_wall_2(*L);
}

void	init_wall_2(labyrinthe L)
{
	int	i;
	int	j;

	for(i = 0 ; i < L.height ; i++)
		for(j = 0 ; j < L.width ; j++)
		{
			L.grid[i][j] += (i == 0) ? TW : bottom_wall(L.grid[i - 1][j]) * TW;//top wall
			L.grid[i][j] += (j == 0) ? LW : right_wall(L.grid[i][j - 1]) * LW;//left wall
			L.grid[i][j] += (i == L.height - 1) ? BW : !(rand() % WALL_PROB) * BW;//bottom wall
			L.grid[i][j] += (j == L.width - 1) ? RW : !(rand() % WALL_PROB) * RW;//right wall
		}
}
*/

void	init_wall(labyrinthe *L)
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


