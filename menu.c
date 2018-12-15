#include	"labyrinthe.h"


void 	home_menu(labyrinthe* L)
{
	char			ctemp;
	char			quit;
	int 			micro_delay;



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
		display_menu(*L,'c', NULL);



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
				if(L->width!=0 && L->height!=0)
			    {
			    	printf("\r   Attention, un Labyrinthe est déjà en mémoire, souhaitez-vous l'écraser (y/n) ? ");
			    	scanf("%1c",&ctemp);
			    	if (ctemp=='y')
			    	{
			    		printf("   Hauteur du nouveau labyrinthe vide : ");
			    		scanf("%d", &(L->height));
			    		printf("   Largeur du nouveau labyrinthe vide : ");
			    		scanf("%d", &(L->width));
						create_empty_lab(L, L->height, L->width);
						edit_menu(L);
					}
				}
				else
				{
			 		printf("\r \n   Hauteur du nouveau labyrinthe vide : ");
		    		scanf("%d", &(L->height));
		    		printf("   Largeur du nouveau labyrinthe vide : ");
		    		scanf("%d", &(L->width));
					create_empty_lab(L, L->height, L->width);
					edit_menu(L);
				}
				break;
		    case 'e': // modifier via l'éditeur
		    	if(L->width!=0 && L->height!=0)
			    {
			    	edit_menu(L);
			    }
		        break;
		    case 'a': // créer aléatoirement
				if(L->width!=0 && L->height!=0)
			    {
			    	printf("\r   Attention, un Labyrinthe est déjà en mémoire, souhaitez-vous l'écraser (y/n) ? ");
			    	scanf("%1c",&ctemp);
			    	if (ctemp=='y')
			    	{
			    		printf("   Hauteur du nouveau labyrinthe aléatoire : ");
			    		scanf("%d", &(L->height));
			    		printf("   Largeur du nouveau labyrinthe aléatoire : ");
			    		scanf("%d", &(L->width));
						create_alea_lab(L, L->height, L->width);
					}
				}
				else
				{
			 		printf("\r \n   Hauteur du nouveau labyrinthe aléatoire : ");
		    		scanf("%d", &(L->height));
		    		printf("   Largeur du nouveau labyrinthe aléatoire : ");
		    		scanf("%d", &(L->width));
					create_alea_lab(L, L->height, L->width);
				}
		    	break;

		    case LARGEUR: // charger depuis un fichier
				if(L->width!=0 && L->height!=0)
			    {
			    	printf("\r   Attention, un Labyrinthe est déjà en mémoire, souhaitez-vous l'écraser (y/n) ? ");
			    	scanf("%1c",&ctemp);
			    	if (ctemp=='y')
						load_file(L);
				}
				else
				{
					printf("\r \n");
					load_file(L);
				}
		        break;
		    case 's': // sauvegarder dans un fichier
		    	if(L->width!=0 && L->height!=0)
			    {
					save_file(L);
				}
		        break;
		    case 'x': // analyser le labyrinthe
		    	if(L->width!=0 && L->height!=0)
			    {
					analysis_menu(L);
				}
		        break;
		    case 'd': // dragon
		    	if (pos_dragon.x == 1)
		    		break;
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
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
									}
									for(int i=0;i<3;i++)
									{
										pos_dragon.x++;
										pos_lab.x++;
										pos_oratoire.x++;
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
										pos_dragon.x++;
										pos_lab.x++;
										pos_oratoire.x++;
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
										pos_dragon.x++;
										pos_lab.x++;
										pos_lab.y--;
										pos_oratoire.x++;
										pos_oratoire.y++;
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
									}
									for(int i=0;i<4;i++)
									{
										pos_dragon.x++;
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
										pos_dragon.x++;
										pos_lab.x++;
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
										pos_dragon.x++;
										pos_lab.x++;
										pos_oratoire.x++;
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
									}
									for(int i=0;i<2;i++)
									{
										pos_dragon.x++;
										pos_lab.x++;
										pos_oratoire.x++;
										display_menu(*L,'c', NULL);
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
		    	if (pos_dragon.x == -40)
		    		break;
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
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
									}
									for(int i=0;i<8;i++)
									{
										pos_knight.x--;
										pos_oratoire.x--;
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
										pos_knight.x--;
										pos_oratoire.x--;
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
										pos_knight.x--;
										pos_oratoire.x--;
										pos_oratoire.y++;
										pos_lab.y--;
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
									}
									for(int i=0;i<33;i++)
									{
										pos_knight.x--;
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
									}
									for(int i=0;i<30;i++)
									{
										pos_dragon.x--;
										pos_knight.x--;
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
									}
									pos_lab.x 		= 19;
									pos_oratoire.x 	= 40;
									for(int i=0;i<11;i++)
									{
										pos_dragon.x--;
										pos_knight.x--;
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
										pos_dragon.x--;
										pos_knight.x--;
										display_menu(*L,'c', NULL);
										usleep(micro_delay);
										pos_dragon.x--;
										pos_knight.x--;
										pos_lab.y++;
										pos_oratoire.y--;
										display_menu(*L,'c', NULL);
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





void 	edit_menu(labyrinthe *L)
{
	unsigned char		ctemp;
	int 				quit;

	L->cursor.x = L->width/2;
	L->cursor.y = L->height/2;

	// loop do
	quit = 0;
	while(quit != 1)
	{
		// refresh
		system("clear");

		display_menu(*L,'e', NULL);
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
		    case 'm': // ESC
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
		    	if (L->cursor.y>=L->height) L->cursor.y=L->height-1;
		        break;
		    case 'q': // LEFT
		    	L->cursor.x--;
		    	if (L->cursor.x<0) L->cursor.x=0;
		        break;
		    case 'd': // RIGHT
		    	L->cursor.x++;
		    	if (L->cursor.x>=L->width) L->cursor.x=L->width-1;
		        break;
		    case 'e': // Select ENTRANCE
		    	L->entrance = L->cursor;
		        break;
		    case 'x': // Select EXIT
		    	L->exit = L->cursor;
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
		    	if (L->cursor.y<L->height-1)
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
		    	if (L->cursor.x<L->width-1)
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






void 	analysis_menu(labyrinthe *L)
{
	unsigned char		ctemp;
	int 				quit;
	path				*chemin;
	path 				temp;

	chemin = NULL;

	// loop do
	quit = 0;
	while(quit != 1)
	{
		// refresh
		system("clear");
		display_menu(*L,'x', chemin);
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
		    case PROFONDEUR: // profondeur
		    	temp = pathfinding(L, PROFONDEUR);
		    	chemin = &temp;
		        break;
		    case LARGEUR: // largeur
		    	temp = BFS(*L);
		    	//temp = pathfinding(L, LARGEUR);
		    	chemin = &temp;
		        break;
		    case 'm': // retour menu
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

