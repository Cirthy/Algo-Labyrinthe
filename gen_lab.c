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
	L->cursor = L->pos_entrance;
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



void	create_lab(labyrinthe *L, int lab_height, int lab_width)
{
	//initialisation
	int					i;
	int					j;
	unsigned char		ctemp;
	long				compteur;
	int 				quit;

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

	


	// loop do
	compteur = 0;
	quit = 0;
	while(quit != 1)
	{
		// refresh
		system("clear");
		creating_display(*L,1);//compteur%2);
		// refresh

		system("/bin/stty raw");
		ctemp = getc(stdin);
		//fflush(stdin);
		system("/bin/stty cooked");


		switch (ctemp)
		{
		    case 27: // ESC
		    	printf("Voulez vous quitter l'éditeur ? (y/n) ");
		    	scanf("%1c",&ctemp);
		    	if (ctemp=='y')
		        	quit = 1;
		        break;
		    case 'z': // UP
		    	L->cursor.y--;
		    	if (L->cursor.y<0) L->cursor.y=0;
		        break;
		    case 's': // DOWN
		    	L->cursor.y++;
		    	if (L->cursor.y>=L->lab_height) L->cursor.y=L->lab_height-1;
		        break;
		    case 'q': // LEFT
		    	L->cursor.x--;
		    	if (L->cursor.x<0) L->cursor.x=0;
		        break;
		    case 'd': // RIGHT
		    	L->cursor.x++;
		    	if (L->cursor.x>=L->lab_width) L->cursor.x=L->lab_width-1;
		        break;
		    case 'e': // Select ENTRANCE
		    	L->pos_entrance = L->cursor;
		        break;
		    case 'x': // Select EXIT
		    	L->pos_exit = L->cursor;
		        break;
		    case '4': // LW
		    	if (L->cursor.x>0)
		    	{
		    		if(left_wall(L->grid[L->cursor.y][L->cursor.x]))
		    		{
		    			L->grid[L->cursor.y][L->cursor.x]   -= LW;
		    			L->grid[L->cursor.y][L->cursor.x-1] -= RW;
		    		}
		    		else
		    		{
		    			L->grid[L->cursor.y][L->cursor.x]   += LW;
		    			L->grid[L->cursor.y][L->cursor.x-1] += RW;
		    		}
		    	}
	        	break;
		    case '2': // BW
		    	if (L->cursor.y<L->lab_height-1)
		    	{
			    	if(bottom_wall(L->grid[L->cursor.y][L->cursor.x]))
			    	{
			    		L->grid[L->cursor.y][L->cursor.x]   -= BW;
			    		L->grid[L->cursor.y+1][L->cursor.x] -= TW;
			    	}
			    	else
			    	{
			    		L->grid[L->cursor.y][L->cursor.x]   += BW;
			    		L->grid[L->cursor.y+1][L->cursor.x] += TW;		    		
			    	}
			    }
		        break;
		    case '6': // RW
		    	if (L->cursor.x<L->lab_width-1)
		    	{
			    	if(right_wall(L->grid[L->cursor.y][L->cursor.x]))
			    	{
			    		L->grid[L->cursor.y][L->cursor.x]   -= RW;
			    		L->grid[L->cursor.y][L->cursor.x+1] -= LW;
			    	}
			    	else
			    	{
			    		L->grid[L->cursor.y][L->cursor.x]   += RW;
			    		L->grid[L->cursor.y][L->cursor.x+1] += LW;
			    	}
			    }
			    break;
		    case '8': // TW
		    	if (L->cursor.y>0)
		    	{
			    	if(top_wall(L->grid[L->cursor.y][L->cursor.x]))
			    	{
			    		L->grid[L->cursor.y][L->cursor.x]   -= TW;
			    		L->grid[L->cursor.y-1][L->cursor.x] -= BW;			    		
			    	}
			    	else
			    	{
			    		L->grid[L->cursor.y][L->cursor.x]   += TW;
			    		L->grid[L->cursor.y-1][L->cursor.x] += BW;			    		
			    	}
			    }
		        break;
			default:
				break;
		}


		//usleep(500000);
		compteur++;
	}




}
