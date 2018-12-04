#include	"labyrinthe.h"


void menu(labyrinthe* L)
{
	char			ctemp;
	char			quit;
	int 			micro_delay;

	init_displayer();


	pos_dragon.x 	= -40;
	pos_dragon.y 	= 1;
	pos_knight.x 	= 100;
	pos_knight.y	= 3;
	pos_lab.x 		= 19;
	pos_lab.y 		= 5;
	pos_oratoire.x 	= 40;
	pos_oratoire.y 	= 5;

/*
			pos_dragon.x 	= -20;
			pos_dragon.y 	= 1;
			pos_knight.x 	= 100;
			pos_knight.y	= 1;
			pos_lab.x 		= 19;
			pos_lab.y 		= 5;
			pos_oratoire.x 	= 40;
			pos_oratoire.y 	= 5;
*/



	micro_delay = 50000;
	quit = 0;


	while(quit != 1)
	{
		// refresh
		menu_display(*L,'c');



		system("/bin/stty raw");
		ctemp = getc(stdin);
		//fflush(stdin);
		system("/bin/stty cooked");


		switch (ctemp)
		{
		    case 27: // ESC
		    	printf("\r     \n   Voulez vous quitter ? (y/n) ");
		    	scanf("%1c",&ctemp);
		    	if (ctemp=='y')
		        	quit = 1;
		        break;
		    case 'n': // créer via l'éditeur
				if(L->lab_width!=0 && L->lab_height!=0)
			    {
			    	printf("\r   Attention, un Labyrinthe est déjà en mémoire, souhaitez-vous l'écraser (y/n) ? ");
			    	scanf("%1c",&ctemp);
			    	if (ctemp=='y')
			    	{
			    		printf("   Hauteur du nouveau labyrinthe vide : ");
			    		scanf("%d", &(L->lab_height));
			    		printf("   Largeur du nouveau labyrinthe vide : ");
			    		scanf("%d", &(L->lab_width));
						create_lab(L, L->lab_height, L->lab_width);
						edit_lab(L);
					}
				}
				else
				{
			 		printf("\r \n   Hauteur du nouveau labyrinthe vide : ");
		    		scanf("%d", &(L->lab_height));
		    		printf("   Largeur du nouveau labyrinthe vide : ");
		    		scanf("%d", &(L->lab_width));
					create_lab(L, L->lab_height, L->lab_width);
					edit_lab(L);
				}
				break;
		    case 'e': // modifier via l'éditeur
		    	if(L->lab_width!=0 && L->lab_height!=0)
			    {
			    	edit_lab(L);
			    }
		        break;
		    case 'a': // créer aléatoirement
				if(L->lab_width!=0 && L->lab_height!=0)
			    {
			    	printf("\r   Attention, un Labyrinthe est déjà en mémoire, souhaitez-vous l'écraser (y/n) ? ");
			    	scanf("%1c",&ctemp);
			    	if (ctemp=='y')
			    	{
			    		printf("   Hauteur du nouveau labyrinthe aléatoire : ");
			    		scanf("%d", &(L->lab_height));
			    		printf("   Largeur du nouveau labyrinthe aléatoire : ");
			    		scanf("%d", &(L->lab_width));
						init_lab(L, L->lab_height, L->lab_width);
					}
				}
				else
				{
			 		printf("\r \n   Hauteur du nouveau labyrinthe aléatoire : ");
		    		scanf("%d", &(L->lab_height));
		    		printf("   Largeur du nouveau labyrinthe aléatoire : ");
		    		scanf("%d", &(L->lab_width));
					init_lab(L, L->lab_height, L->lab_width);
				}
		    	break;

		    case 'l': // charger depuis un fichier
				if(L->lab_width!=0 && L->lab_height!=0)
			    {
			    	printf("\r   Attention, un Labyrinthe est déjà en mémoire, souhaitez-vous l'écraser (y/n) ? ");
			    	scanf("%1c",&ctemp);
			    	if (ctemp=='y')
						read_file(L);
				}
				else
				{
					printf("\r \n");
					read_file(L);
				}
		        break;
		    case 's': // sauvegarder dans un fichier
		    	if(L->lab_width!=0 && L->lab_height!=0)
			    {
					save_file(L);
				}
		        break;
		    case 'x': // analyser le labyrinthe
		    	if(L->lab_width!=0 && L->lab_height!=0)
			    {
					analyse_menu(L);
				}
		        break;
		    case 'd': // dragon
		    	printf("\r \r");
		    	system("/bin/stty raw");
				ctemp = getc(stdin);
				printf("\r \r");
				if (ctemp=='r')
				{
					ctemp = getc(stdin);
					printf("\r \r");
					if (ctemp=='a')
					{
						ctemp = getc(stdin);
						printf("\r \r");
						if (ctemp=='g')
						{
							ctemp = getc(stdin);
							printf("\r \r");
							if (ctemp=='o')
							{
								ctemp = getc(stdin);
								//printf("\r \r");
								if (ctemp=='n')
								{
									system("/bin/stty cooked");
									//déplacement des paterns
									for(int i=0;i<18;i++)
									{
										pos_dragon.x++;
										menu_display(*L,'c');
										usleep(micro_delay);
									}
									for(int i=0;i<3;i++)
									{
										pos_dragon.x++;
										pos_lab.x++;
										pos_oratoire.x++;
										menu_display(*L,'c');
										usleep(micro_delay);
										pos_dragon.x++;
										pos_lab.x++;
										pos_oratoire.x++;
										menu_display(*L,'c');
										usleep(micro_delay);
										pos_dragon.x++;
										pos_lab.x++;
										pos_lab.y--;
										pos_oratoire.x++;
										pos_oratoire.y++;
										menu_display(*L,'c');
										usleep(micro_delay);
									}
									for(int i=0;i<4;i++)
									{
										pos_dragon.x++;
										menu_display(*L,'c');
										usleep(micro_delay);
										pos_dragon.x++;
										pos_lab.x++;
										menu_display(*L,'c');
										usleep(micro_delay);
										pos_dragon.x++;
										pos_lab.x++;
										pos_oratoire.x++;
										menu_display(*L,'c');
										usleep(micro_delay);
									}
									for(int i=0;i<2;i++)
									{
										pos_dragon.x++;
										pos_lab.x++;
										pos_oratoire.x++;
										menu_display(*L,'c');
										usleep(micro_delay);
									}
									//positions finals atteintes
								}
							}
						}
					}
				}
				system("/bin/stty cooked");
	        	break;
		    case 'k': // knight
		    	printf("\r \r");
		    	system("/bin/stty raw");
				ctemp = getc(stdin);
				printf("\r \r");
				if (ctemp=='n')
				{
					ctemp = getc(stdin);
					printf("\r \r");
					if (ctemp=='i')
					{
						ctemp = getc(stdin);
						printf("\r \r");
						if (ctemp=='g')
						{
							ctemp = getc(stdin);
							printf("\r \r");
							if (ctemp=='h')
							{
								ctemp = getc(stdin);
								//printf("\r \r");
								if (ctemp=='t')
								{
									system("/bin/stty cooked");

									for(int i=0;i<3;i++)
									{
										pos_knight.x--;
										menu_display(*L,'c');
										usleep(micro_delay);
									}
									for(int i=0;i<8;i++)
									{
										pos_knight.x--;
										pos_oratoire.x--;
										menu_display(*L,'c');
										usleep(micro_delay);
										pos_knight.x--;
										pos_oratoire.x--;
										menu_display(*L,'c');
										usleep(micro_delay);
										pos_knight.x--;
										pos_oratoire.x--;
										pos_oratoire.y++;
										pos_lab.y--;
										menu_display(*L,'c');
										usleep(micro_delay);
									}
									for(int i=0;i<33;i++)
									{
										pos_knight.x--;
										menu_display(*L,'c');
										usleep(micro_delay);
									}
									for(int i=0;i<30;i++)
									{
										pos_dragon.x--;
										pos_knight.x--;
										menu_display(*L,'c');
										usleep(micro_delay);
									}
									pos_lab.x 		= 19;
									pos_oratoire.x 	= 40;
									for(int i=0;i<11;i++)
									{
										pos_dragon.x--;
										pos_knight.x--;
										menu_display(*L,'c');
										usleep(micro_delay);
										pos_dragon.x--;
										pos_knight.x--;
										menu_display(*L,'c');
										usleep(micro_delay);
										pos_dragon.x--;
										pos_knight.x--;
										pos_lab.y++;
										pos_oratoire.y--;
										menu_display(*L,'c');
										usleep(micro_delay);
									}
									//usleep(2000000);
									pos_dragon.x 	= -40;
									pos_knight.x 	= 100;
								}
							}
						}
					}
				}
				system("/bin/stty cooked");
		   		break;
			default:
				break;
		}
	}
}





void 	edit_lab(labyrinthe *L)
{
	unsigned char		ctemp;
	int 				quit;

	// loop do
	quit = 0;
	while(quit != 1)
	{
		// refresh
		system("clear");

		menu_display(*L,'e');
		// refresh

		system("/bin/stty raw");
		ctemp = getc(stdin);
		//fflush(stdin);
		system("/bin/stty cooked");


		switch (ctemp)
		{
		    case 27: // ESC
		    	printf("\r        (Labyrinthe en mémoire)\n        Voulez vous quitter l'éditeur ? (y/n) ");
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
	}




}






void 	analyse_menu(labyrinthe *L)
{
	unsigned char		ctemp;
	int 				quit;

	// loop do
	quit = 0;
	while(quit != 1)
	{
		// refresh
		system("clear");

		menu_display(*L,'x');
		// refresh

		system("/bin/stty raw");
		ctemp = getc(stdin);
		//fflush(stdin);
		system("/bin/stty cooked");


		switch (ctemp)
		{
		    case 27: // ESC
		    	printf("\r        \n        Voulez vous quitter l'analyseur ? (y/n) ");
		    	scanf("%1c",&ctemp);
		    	if (ctemp=='y')
		        	quit = 1;
		        break;
		    case 'h': // heuristique
		    	
		        break;
		    case 'b': // DOWN
		       
		        break;
		    case 'l': // LEFT

		        break;
		    case 's': // RIGHT

		        break;
		    case 'm': // Select ENTRANCE
		    	printf("\r        \n        Voulez vous quitter l'analyseur ? (y/n) ");
		    	scanf("%1c",&ctemp);
		    	if (ctemp=='y')
		        	quit = 1;
		        break;
			default:
				break;
		}


		//usleep(500000);
	}
}

