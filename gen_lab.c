#include	"labyrinthe.h"

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
	init_wall(*L);
}

void	init_wall(labyrinthe L)
{
	int	i;
	int	j;

	for(i = 0 ; i < L.lab_height ; i++)
		for(j = 0 ; j < L.lab_width ; j++)
		{
			L.grid[i][j] += i == 0 ? TW : bottom_wall(L.grid[i - 1][j]) * TW;//top wall
			L.grid[i][j] += j == 0 ? LW : right_wall(L.grid[i][j - 1]) * LW;//left wall
			L.grid[i][j] += i == L.lab_height - 1 ? BW : !(rand() % WALL_PROB) * BW;//bottom wall
			L.grid[i][j] += j == L.lab_width - 1 ? RW : !(rand() % WALL_PROB) * RW;//right wall
		}
}

char	left_wall(unsigned short cell)
{
	return cell % 2;
}

char	bottom_wall(unsigned short cell)
{
	return (cell / 2) % 2;
}

char	right_wall(unsigned short cell)
{
	return (cell / 4) % 2;
}

char	top_wall(unsigned short cell)
{
	return (cell / 8) % 2;
}


char 	path_to(path* p, int x1, int y1, int x2, int y2)
{
	for (int i=0 ; i<p->length ; i++)
	{
		if (p->cells[i].x == x1 && p->cells[i].y == y1)
		{
			if ((i==0 && p->cells[i+1].x == x2 && p->cells[i+1].y == y2) || (i==p->length-1 && p->cells[i-1].x == x2 && p->cells[i-1].y == y2) || (p->cells[i+1].x == x2 && p->cells[i+1].y == y2) || (p->cells[i-1].x == x2 && p->cells[i-1].y == y2))
				return 1;
		}
	}
	return 0;
}



void	create_lab(labyrinthe *L, int lab_height, int lab_width)
{
	//initialisation
	int		i;
	int		j;

	L->grid = (unsigned short **)malloc(sizeof(unsigned short *) * lab_height);
	for(i = 0 ; i < lab_height ; i++)
		(L->grid)[i] = (unsigned short *)calloc(sizeof(unsigned short), lab_width);
	L->lab_height = lab_height;
	L->lab_width = lab_width;
	L->pos_entrance.x=0;
	L->pos_entrance.y=0;
	L->pos_exit.x=0;
	L->pos_exit.y=0;
	L->cursor.x=0;
	L->cursor.y=0;


	for(i = 0 ; i < L->lab_height ; i++)
	{
		L->grid[i][0] += LW; //left wall
		L->grid[i][L->lab_width-1] += RW; //right wall
	}
	for(j = 0 ; j < L->lab_width ; j++)
	{
		L->grid[0][j] += TW; //top wall
		L->grid[L->lab_height-1][j] += BW; //bottom wall

	}
}


