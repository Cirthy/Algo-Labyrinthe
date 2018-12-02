#include	"labyrinthe.h"


void menu(labyrinthe* L)
{
	char			ctemp;
	char			quit;
	position 		pos_dragon;
	position 		pos_knight;
	position 		pos_lab;
	position 		pos_oratoire;
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
		menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);



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

		        break;
		    case 'e': // modifier via l'éditeur

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
			save_file(L);

		        break;
		    case 'x': // analyser le labyrinthe

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
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
									}
									for(int i=0;i<3;i++)
									{
										pos_dragon.x++;
										pos_lab.x++;
										pos_oratoire.x++;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
										pos_dragon.x++;
										pos_lab.x++;
										pos_oratoire.x++;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
										pos_dragon.x++;
										pos_lab.x++;
										pos_lab.y--;
										pos_oratoire.x++;
										pos_oratoire.y++;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
									}
									for(int i=0;i<4;i++)
									{
										pos_dragon.x++;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
										pos_dragon.x++;
										pos_lab.x++;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
										pos_dragon.x++;
										pos_lab.x++;
										pos_oratoire.x++;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
									}
									for(int i=0;i<2;i++)
									{
										pos_dragon.x++;
										pos_lab.x++;
										pos_oratoire.x++;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
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
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
									}
									for(int i=0;i<8;i++)
									{
										pos_knight.x--;
										pos_oratoire.x--;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
										pos_knight.x--;
										pos_oratoire.x--;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
										pos_knight.x--;
										pos_oratoire.x--;
										pos_oratoire.y++;
										pos_lab.y--;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
									}
									for(int i=0;i<33;i++)
									{
										pos_knight.x--;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
									}
									for(int i=0;i<30;i++)
									{
										pos_dragon.x--;
										pos_knight.x--;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
									}
									pos_lab.x 		= 19;
									pos_oratoire.x 	= 40;
									for(int i=0;i<11;i++)
									{
										pos_dragon.x--;
										pos_knight.x--;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
										pos_dragon.x--;
										pos_knight.x--;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
										usleep(micro_delay);
										pos_dragon.x--;
										pos_knight.x--;
										pos_lab.y++;
										pos_oratoire.y--;
										menu_display(*L,'c',pos_dragon,pos_knight,pos_lab,pos_oratoire);
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




