#include	"labyrinthe.h"


void	create_empty_lab(labyrinthe *L, int height, int width)
{
	//initialisation
	int		i;
	int		j;

	L->grid = (unsigned short **)malloc(sizeof(unsigned short *) * height);
	for(i = 0 ; i < height ; i++)
		(L->grid)[i] = (unsigned short *)calloc(sizeof(unsigned short), width);
	L->lab_height = height;
	L->lab_width = width;
	L->pos_entrance.x=0;
	L->pos_entrance.y=0;
	L->pos_exit.x=0;
	L->pos_exit.y=0;
	L->cursor.x=0;
	L->cursor.y=0;

	for(i = 0 ; i < L->lab_height ; i++)
	{
		L->grid[i][0] += LW; 				//left wall
		L->grid[i][L->lab_width-1] += RW; 	//right wall
	}
	for(j = 0 ; j < L->lab_width ; j++)
	{
		L->grid[0][j] += TW; 				//top wall
		L->grid[L->lab_height-1][j] += BW; 	//bottom wall
	}
}


void 	create_alea_lab(labyrinthe *L, int height, int width)
{
	create_empty_lab(L, height, width);
	srand(time(NULL));
	L->pos_entrance.x = rand() % L->lab_width;
	L->pos_entrance.y = rand() % L->lab_height;
	L->pos_exit.x     = rand() % L->lab_width;
	L->pos_exit.y     = rand() % L->lab_height;
	init_wall(L);
}

/*
void	init_lab(labyrinthe *L, int lab_height, int lab_width)
{
	int			i;
	position	temp;

	L->grid = (unsigned short **)malloc(sizeof(unsigned short *) * lab_height);
	for(i = 0 ; i < lab_height ; i++)
		(L->grid)[i] = (unsigned short *)calloc(sizeof(unsigned short), lab_width);
	L->lab_height = lab_height;
	L->lab_width = lab_width;
	temp.x = rand() % lab_width;
	temp.y = rand() % lab_height;
	L->pos_entrance = temp;
	temp.x = rand() % lab_width;
	temp.y = rand() % lab_height;
	L->pos_exit = temp;
	L->cursor.x = 0;
	L->cursor.y = 0;
	init_wall_2(*L);
}

void	init_wall_2(labyrinthe L)
{
	int	i;
	int	j;

	for(i = 0 ; i < L.lab_height ; i++)
		for(j = 0 ; j < L.lab_width ; j++)
		{
			L.grid[i][j] += (i == 0) ? TW : bottom_wall(L.grid[i - 1][j]) * TW;//top wall
			L.grid[i][j] += (j == 0) ? LW : right_wall(L.grid[i][j - 1]) * LW;//left wall
			L.grid[i][j] += (i == L.lab_height - 1) ? BW : !(rand() % WALL_PROB) * BW;//bottom wall
			L.grid[i][j] += (j == L.lab_width - 1) ? RW : !(rand() % WALL_PROB) * RW;//right wall
		}
}
*/

void	init_wall(labyrinthe *L)
{
	for(int i = 0 ; i < L->lab_height ; i++)
		for(int j = 0 ; j < L->lab_width ; j++)
		{
			L->grid[i][j] += (i == 0) ? 0 : bottom_wall(L->grid[i - 1][j]) * TW;//top wall
			L->grid[i][j] += (j == 0) ? 0 : right_wall(L->grid[i][j - 1]) * LW;//left wall
			L->grid[i][j] += (i == L->lab_height - 1) ? 0 : !(rand() % WALL_PROB) * BW;//bottom wall
			L->grid[i][j] += (j == L->lab_width - 1) ? 0 : !(rand() % WALL_PROB) * RW;//right wall
		}
}


