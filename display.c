#include	"labyrinthe.h"


void	display_lab_V1(labyrinthe L)
{
	int i;
	int j;
	for(i = 0 ; i < L.height ; i++)
	{
		printf("    ");
		for(j = 0 ; j < L.width ; j++)
		{
			printf("+");
			((L.grid[i][j]/8)%2) ?	printf("---") : printf("   ");
		}
		printf("+\n    ");
		for(j = 0 ; j < L.width ; j++)
		{
			(L.grid[i][j]%2) ? printf("|") : printf(" ");
			//dist = get_distance(L,temp);
			if (L.entrance.x==j && L.entrance.y==i)
			{
				if (L.exit.x==j && L.exit.y==i)
					printf("EX!"); // le ! est de la part de Clément :)
				else
					printf(" E ");
			}
			else if (L.exit.x==j && L.exit.y==i)
				printf(" X ");
			else if (pos_equal(L.cursor, pos(j, i)))
				printf(" C ");
			else
				printf("   ");
		}
		printf("|\n");
	}
	printf("    ");
	for(j = 0 ; j < L.width ; j++)
	{
		printf("+---");
	}
	printf("+\n\n");
}

void	display_lab_V2(labyrinthe L, char mode, path* plusCourt)
{
	int i;
	int j;
	position maxSize;
	// │ ─ ┌ ┐ └ ┘ ├ ┤ ┬ ┴ ┼ · ╴ ╶ ╵ ╷

	maxSize = get_max_size_lab();

	if (L.height>maxSize.y || L.width>maxSize.x)
	{
		printf("\n\n\tLe labyrinthe en mémoire est trop grand pour etre afficher.\n");
		printf("\tCe problème peut etre reglé on modifiant la taille de la console.\n");
		printf("\tLa taille maximum des labyrinthes affichable dans la console actuelle est : %dx%d.\n\n", maxSize.y,maxSize.x);
		if (mode=='e')
			printf("\tLe mode éditeur n'est pas viable si le labyrinthe ne peut pas s'afficher,\n\tmerci de pressé ESC ou -m- pour revenir au menu principal.\n\n");
		printf("\tVeuillez nous excusez pour le dérangement occasioné.\n");
		printf("\t\t\tps : Achetez un écran plus grand.\n");
		printf("\t\t\tBonne journée !\n");
		return;
	}






	if (mode=='e')
	{
		printf("     ");
		for(j=0 ; j<L.width ; j++)
			printf("%2d  ",j);
	}
	printf("\n");



	for(i=0 ; i<L.height ; i++)
	{
		printf("    ");
		for(j=0 ; j<L.width ; j++)
		{
			if(i==0)
			{
				if(j==0)
					printf("┌───");
				else
				{
					(L.grid[i][j]%2) ? printf("┬───") : printf("────");

				}
				if (j==L.width-1)
					printf("┐");
			}
			else
			{
				if(j==0)
				{
					if ((L.grid[i][j]/8)%2)
						printf("├───");
					else
					{
						printf("│ ");
						if (plusCourt && is_in_path(plusCourt,j,i-1,j,i))
						{
							set_color(BLOOD,RED);
							printf("│ ");
							set_color(DEFAULT,WHITE);
						}
						else
							printf("  ");
					}
				}
				else
				{
					if((L.grid[i-1][j-1]/4)%2) // R? ?
					{
						if((L.grid[i-1][j-1]/2)%2) // RD ?
						{
							if(L.grid[i][j]%2) // RD L?
							{
								if((L.grid[i][j]/8)%2) // RD LU
									printf("┼───");
								else // RD L
								{
									printf("┤ ");
									if (plusCourt && is_in_path(plusCourt,j,i-1,j,i))
									{
										set_color(BLOOD,RED);
										printf("│ ");
										set_color(DEFAULT,WHITE);
									}
									else
										printf("  ");
								}	
							}
							else if((L.grid[i][j]/8)%2) // RD U
								printf("┴───");
							else // RD NONE
							{
								printf("┘ ");
								if (plusCourt && is_in_path(plusCourt,j,i-1,j,i))
								{
									set_color(BLOOD,RED);
									printf("│ ");
									set_color(DEFAULT,WHITE);
								}
								else
									printf("  ");
							}	
						}
						else // R ?
						{
							if(L.grid[i][j]%2) // R L?
							{
								if((L.grid[i][j]/8)%2) // R LU
									printf("├───");
								else // R L
								{
									printf("│ ");
									if (plusCourt && is_in_path(plusCourt,j,i-1,j,i))
									{
										set_color(BLOOD,RED);
										printf("│ ");
										set_color(DEFAULT,WHITE);
									}
									else
										printf("  ");
								}		
							}
							else if((L.grid[i][j]/8)%2) // R U
								printf("└───");
							else // R NONE
							{
								printf("╵ ");
								if (plusCourt && is_in_path(plusCourt,j,i-1,j,i))
								{
									set_color(BLOOD,RED);
									printf("│ ");
									set_color(DEFAULT,WHITE);
								}
								else
									printf("  ");
							}	
						}
					}
					else if((L.grid[i-1][j-1]/2)%2) // D NONE
					{
						if(L.grid[i][j]%2) // D L?
						{
							if((L.grid[i][j]/8)%2) // D LU
								printf("┬───");
							else // D L
							{
								printf("┐ ");
								if (plusCourt && is_in_path(plusCourt,j,i-1,j,i))
								{
									set_color(BLOOD,RED);
									printf("│ ");
									set_color(DEFAULT,WHITE);
								}
								else
									printf("  ");
							}	

						}
						else if((L.grid[i][j]/8)%2) // D U
							printf("────");
						else // D NONE
						{
							printf("╴ ");
							if (plusCourt && is_in_path(plusCourt,j,i-1,j,i))
							{
								set_color(BLOOD,RED);
								printf("│ ");
								set_color(DEFAULT,WHITE);
							}
							else
								printf("  ");
						}
					}
					else // NONE ?
					{
						if(L.grid[i][j]%2) // NONE L?
						{
							if((L.grid[i][j]/8)%2) // NONE LU
								printf("┌───");
							else // NONE L
							{
								printf("╷ ");
								if (plusCourt && is_in_path(plusCourt,j,i-1,j,i))
								{
									set_color(BLOOD,RED);
									printf("│ ");
									set_color(DEFAULT,WHITE);
								}
								else
									printf("  ");
							}	
						}
						else if((L.grid[i][j]/8)%2) // NONE U
							printf("╶───");
						else // NONE NONE
						{
							printf("· ");
							if (plusCourt && is_in_path(plusCourt,j,i-1,j,i))
							{
								set_color(BLOOD,RED);
								printf("│ ");
								set_color(DEFAULT,WHITE);
							}
							else
								printf("  ");
						}
					}
				}
				if (j==L.width-1)
					((L.grid[i][j]/8)%2) ? printf("┤") : printf("│");

			}
		}
		(mode=='e') ? printf("\n %2d ",i): printf("\n    ");
		for(j=0 ; j<L.width ; j++)
		{
			if (L.grid[i][j]%2)
				printf("│");
			else if (plusCourt && is_in_path(plusCourt,j,i,j-1,i))
				{
					set_color(BLOOD,RED);
					printf("─");
					set_color(DEFAULT,WHITE);
				}
			else
				printf(" ");
			if (mode == 'c')
			{
				if (L.entrance.x==j && L.entrance.y==i)
				{
					if (L.exit.x==j && L.exit.y==i)
						printf("EX!"); //// le ! est de la part de Clément :)
					else
						printf(" E ");
				}
				else if (L.exit.x==j && L.exit.y==i)
					printf(" X ");
				else
				{
					if (plusCourt)
					{
						set_color(BLOOD,RED);
						if (is_in_path(plusCourt,j,i,j,i-1) && is_in_path(plusCourt,j,i,j,i+1))
							printf(" │ ");
						else if (is_in_path(plusCourt,j,i,j+1,i) && is_in_path(plusCourt,j,i,j-1,i))
							printf("───");
						else if (is_in_path(plusCourt,j,i,j+1,i) && is_in_path(plusCourt,j,i,j,i+1))
							printf(" ┌─");
						else if (is_in_path(plusCourt,j,i,j-1,i) && is_in_path(plusCourt,j,i,j,i+1))
							printf("─┐ ");
						else if (is_in_path(plusCourt,j,i,j,i-1) && is_in_path(plusCourt,j,i,j+1,i))
							printf(" └─");
						else if (is_in_path(plusCourt,j,i,j,i-1) && is_in_path(plusCourt,j,i,j-1,i))
							printf("─┘ ");
						else 
							printf("   ");
						set_color(DEFAULT,WHITE);
					}
					else
						printf("   ");
				}
			}
			else if (mode == 'e')
			{
				if (L.cursor.x==j && L.cursor.y==i)
				{
					set_color(BLOOD,YELLOW);
					printf(" ☐ ");
					set_color(DEFAULT,WHITE);
				}
				else
				{
					if (L.entrance.x==j && L.entrance.y==i)
					{
						if (L.exit.x==j && L.exit.y==i)
							printf("EX!"); //// le ! est de la part de Clément :)
						else
							printf(" E ");
					}
					else if (L.exit.x==j && L.exit.y==i)
						printf(" X ");
					else
						printf("   ");
				}			
			}
		}
		printf("│\n");
	}
	printf("    └───");
	for(j=1 ; j<L.width ; j++)
	{
		(L.grid[L.height-1][j]%2) ? printf("┴───") : printf("────");
	}
	printf("┘\n\n");
}


void 	display_path(path* chemin)
{
	if (chemin)
	{
		if(chemin->length == -1)
			printf("Pas de chemin\n");
		else
		{
			printf("Longueur %d : ", chemin->length);
			for(int i = 0 ; i <= chemin->length ; i++)
			{
				display_position(chemin->cells[i]);
				printf("%s", i == chemin->length ? "" : " -> ");
			}
			printf("\n");
		}
	}
}


void	display_distance(labyrinthe *L)
{
	for(int i = 0 ; i < L->height ; i++)
	{
		for(int j = 0 ; j < L->width ; j++)
			printf("%d\t", get_distance_12b(L, pos(j, i)));
	printf("\n");
	}
	printf("\n\n");
}


void	display_tab_pos(position *tab_pos)
{
	int	i = -1;

	while(!pos_equal(tab_pos[++i], pos(-1, -1)))
	{
		display_position(tab_pos[i]);
		printf("->");
	}
	printf("\n");
}


void	display_marked(labyrinthe L)
{
	int i, j;
	position pos;

	for(i = 0 ; i < L.height ; i++)
	{
		for(j = 0 ; j < L.width ; j++)
		{
			pos.x = j;
			pos.y = i;
			if(is_marked(L, pos))
				printf("1\t");
			else
				printf("0\t");
		}
		printf("\n");
	}
	printf("\n\n");
}


void	display_visit_order(labyrinthe L, position *V)
{
	for(int i = 0 ; i < L.width * L.height ; i++)
		printf("(%d, %d) ", V[i].y, V[i].x);
	printf("\n");
}


void	display_menu(labyrinthe L, char mode, path* chemin)
{
	/*
	mode :
	'c' mode classic
	'e' mode édition
	'x' mode analyse
	*/
	printf("%c\n", mode);
	// refresh
	system("clear");
	char ctemp;
	for(int i = 0 ; i < 16 ; i++)
	{
		for(int j = 0 ; j < 100 ; j++)
		{
			set_color(DEFAULT,8);
			ctemp = '$';
			if(i>=pos_dragon.y && j>=pos_dragon.x && i<=pos_dragon.y+14 && j<=pos_dragon.x+39)
			{
				ctemp = dragon[i-pos_dragon.y][j-pos_dragon.x];
				if (ctemp!='$')
				{
					set_color(DEFAULT,LIGHT_GREY);
				}
			}
			if(i>=pos_lab.y && j>=pos_lab.x && i<=pos_lab.y+5 && j<=pos_lab.x+21)
			{
				set_color(BLOOD,YELLOW);
				ctemp = lab[i-pos_lab.y][j-pos_lab.x];
			}
			if(i>=pos_oratoire.y && j>=pos_oratoire.x && i<=pos_oratoire.y+5 && j<=pos_oratoire.x+40)
			{
				set_color(BLOOD,YELLOW);
				ctemp = oratoire[i-pos_oratoire.y][j-pos_oratoire.x];
			}
			if(i>=pos_knight.y && j>=pos_knight.x && i<=pos_knight.y+9 && j<=pos_knight.x+13)
			{
				ctemp = knight[i-pos_knight.y][j-pos_knight.x];
			}

			printf("%c",ctemp);
		}
		printf("\n");
	}






	printf("\n");
	set_color(BLOOD,RED);
	printf("\tBienvenue sur ");
	set_color(UNDERLINE,RED);
	printf("Lab Oratoire");
	set_color(DEFAULT,RED);
	set_color(BLOOD,RED);
	printf(", gestionnaire de labyrinthes, que voulez vous faire ?\n");
	set_color(DEFAULT, WHITE);



	switch (mode)
	{
	    case 'c': // classic
			if(L.width==0 || L.height==0)
			{
				printf("\n\tIl n'y a pas de labyrinthe chargé.\n");
				printf(" -n- créer un labyrinthe via l'éditeur.\n");
				printf(" -a- générer un labyrinthe aléatoirement.\n");
				printf(" -l- charger un labyrinthe depuis un fichier.\n");
			}
			else
			{
				printf("\n\tIl y a un labyrinthe de taille %dx%d en mémoire.\n",L.height,L.width);
				printf(" -n- créer un labyrinthe via l'éditeur.\n");
				printf(" -e- modifier le labyrinthe via l'éditeur.\n");
				printf(" -a- générer un labyrinthe aléatoirement.\n");
				printf(" -l- charger un labyrinthe depuis un fichier.\n");
				printf(" -s- sauvegarder le labyrinthe courant dans un fichier.\n");
				printf(" -x- analyser le labyrinthe courant\n\n");
				display_lab_V2(L,mode,NULL);			
			}
			break;
		case 'e': // édition
				printf("\n\tBienvenue sur le menu d'édition du labyrinthe courant.\n");
				printf("\tLa labyrinthe courant est de taille %dx%d.\n",L.height,L.width);
				printf(" -zqsd- déplacer le curseur dans le labyrinthe.\n");
				printf(" -8462- placer/retirer un mur.\n");
				printf(" -e- positionner l'entrée.\n");
				printf(" -x- positionner la sortie.\n");
				printf(" -m- sauvegarder et quitter l'éditeur.\n\n");
				display_lab_V2(L,mode,NULL);
			break;
		case 'x': // analyse
				printf("\n\tBienvenue sur le menu d'analyse du labyrinthe courant.\n");
				printf("La labyrinthe courant est de taille %dx%d.\n",L.height,L.width);
				printf(" -p- lancer une recherche de plus court chemin par parcours en profondeur.\n");
				printf(" -l- lancer une recherche de plus court chemin par parcours en largeur.\n");
				printf(" -m- revenir au menu principal.\n\n\n\n");

				if (chemin)
				{
					if (chemin->type=='p')
						printf("Analyse par parcours en profondeur, ");
					if (chemin->type=='l')
						printf("Analyse par parcours en largeur, ");
					if (chemin->length == NO_PATH)
						{
							printf("pas de chemin trouvé !");
							display_lab_V2(L,'c',NULL);
						}
					else
						{
							printf("un chemin minimum trouvé de longeur %d.", chemin->length);
							display_lab_V2(L,'c',chemin);
						}
				}
				else
					display_lab_V2(L,'c',NULL);
			break;
	}
}



void 	display_position(position p)
{
	printf("[%d:%d]", p.x, p.y);
}

void 	display_positions_tab(position* T, int size_T)
{
	int i;
	for (i=0; i<size_T; i++)
	{
		printf("%d : ", i);
		display_position(T[i]);
		printf("\n");
	}
	printf("\n");
}




void	init_displayer()
{
	dragon[0]  = "$$$$$$$$$$$$$$$$$Y/'$$$$P'a$$$$$$$$$$$$$";
	dragon[1]  = "$$$$$$$$$$\",` /,/,mT$$$$ d$$$$$$$$$$$$$$";
	dragon[2]  = "$$$$$$l',` , '/d$$$$P^$a `^a`W$$$$$$$$$$";
	dragon[3]  = "$$$l', ` ,   |d$$$P^$'   _  _ ==~a$$$$$$";
	dragon[4]  = "$$l.`  .     \\'i$^4'   _eP$$$$$$$$$$$$$$";
	dragon[5]  = "$l '  .         /   ,  $$$$' `$~$$$$$$$$";
	dragon[6]  = "$; ' ,              l /^' .,$oa$$$$$$$$$";
	dragon[7]  = "$b ' ,        .     (_ ,1$$$$$$'$$$$$$$$";
	dragon[8]  = "$$ , ,      .;       _$$$$$$$P $a$$$$$$$";
	dragon[9]  = "$$, ,`    .$Ly        lM\"^ ,  ,$$$$$$$'$";
	dragon[10] = "$$$, ,`   d$Liy      /'   edb $$$$$$$'$$";
	dragon[11] = "$$$$$,,'. $$$Li     (    d$$$$$$$$$$'$$$";
	dragon[12] = "$$$$$$$,' v$$$Li4.   `  `Q$$$$$$$P',$$$$";
	dragon[13] = "$$$$$$$$$,$$$$$$$L44., . .     ,,;d$$$$$";
	dragon[14] = "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";

	knight[0] = "           |  ";
    knight[1] = "           |  ";
    knight[2] = "         / +  ";
    knight[3] = "   .=*._?.//  ";
    knight[4] = "   |/.\\'H)'   ";
    knight[5] = " .--_) '<.    ";
    knight[6] = "   /^.   b\\=_ ";
    knight[7] = "   '   '-(/ ~~";
    knight[8] = "        | \\   ";
    knight[9] = "       '  '   ";

    lab[0] = "   _          _       ";
	lab[1] = "  | |    __ _| |__    ";
	lab[2] = "  | |   / _` | '_ \\   ";
	lab[3] = "  | |__| (_| | |_) |  ";
	lab[4] = "  |_____\\__,_|_.__/   ";
	lab[5] = "                      ";

	oratoire[0] = "    ___            _        _            ";
	oratoire[1] = "   / _ \\ _ __ __ _| |_ ___ (_)_ __ ___   ";
	oratoire[2] = "  | | | | '__/ _` | __/ _ \\| | '__/ _ \\  ";
	oratoire[3] = "  | |_| | | | (_| | || (_) | | | |  __/  ";
	oratoire[4] = "   \\___/|_|  \\__,_|\\__\\___/|_|_|  \\___|  ";
	oratoire[5] = "                                         ";
}



