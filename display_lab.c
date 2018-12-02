#include	"labyrinthe.h"


void	display(labyrinthe L)
{
	int i;
	int j;
	printf("\n");
	for(i = 0 ; i < L.lab_height ; i++)
	{
		printf("\t");
		for(j = 0 ; j < L.lab_width ; j++)
		{
			printf("+");
			(L.grid[i][j]>=8) ?	printf("---") : printf("   ");
		}
		printf("+\n\t");
		for(j = 0 ; j < L.lab_width ; j++)
		{
			(L.grid[i][j]%2==1) ? printf("|") : printf(" ");

			if (L.pos_entrance.x==j && L.pos_entrance.y==i)
			{
				if (L.pos_exit.x==j && L.pos_exit.y==i)
					printf("EX!"); // le ! est de la part de Clément :)
				else
					printf(" E ");
			}
			else if (L.pos_exit.x==j && L.pos_exit.y==i)
				printf(" X ");
			else
				printf("   ");

		}
		printf("|\n");
	}
	printf("\t");
	for(j = 0 ; j < L.lab_width ; j++)
	{
		printf("+---");
	}
	printf("+\n\n");
}



void	creating_display(labyrinthe L, int half)
{
	int i;
	int j;
	printf("\n\n\n\n\n\nzqsd pour se déplacer et 8462 pour placer/retirer les murs :\n");
	for(i = 0 ; i < L.lab_height ; i++)
	{
		for(j = 0 ; j < L.lab_width ; j++)
		{
			printf("+");
			(L.grid[i][j]>=8) ?	printf("---") : printf("   ");
		}
		printf("+\n");
		for(j = 0 ; j < L.lab_width ; j++)
		{
			(L.grid[i][j]%2==1) ? printf("|") : printf(" ");
			if (half == 1 && L.cursor.x == j && L.cursor.y == i)
				printf(" _ ");
			else
				printf("%2hu ",L.grid[i][j]);
		}
		printf("|\n");
	}
	for(j = 0 ; j < L.lab_width ; j++)
	{
		printf("+---");
	}
	printf("+\n\tvaleur courante    : %d\n",L.grid[L.cursor.y][L.cursor.x]);
	printf(   "\tposition d'entrée  : (%d,%d)\n",L.pos_entrance.x ,L.pos_entrance.y);
	printf(   "\tposition de sortie : (%d,%d)\n\n\n\n\n\n\n",L.pos_exit.x ,L.pos_exit.y);
}



void	menu_display(labyrinthe L, char mode, position pos_dragon, position pos_knight, position pos_lab, position pos_oratoire)
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





	if(L.lab_width==0 || L.lab_height==0)
	{
		printf("\n\tIl n'y a pas de labyrinthe chargé.\n");
		printf(" -n- créer un labyrinthe via l'éditeur.\n");
		printf(" -a- générer un labyrinthe aléatoirement.\n");
		printf(" -l- charger un labyrinthe depuis un fichier.\n");
	}
	else
	{
		printf("\n\tIl y a un labyrinthe de taille %d %d en mémoire.\n",L.lab_width,L.lab_height);
		printf(" -n- créer un labyrinthe via l'éditeur.\n");
		printf(" -e- modifier le labyrinthe via l'éditeur.\n");
		printf(" -a- générer un labyrinthe aléatoirement.\n");
		printf(" -l- charger un labyrinthe depuis un fichier.\n");
		printf(" -s- sauvegarder le labyrinthe courant dans un fichier.\n");
		printf(" -x- analyser le labyrinthe courant\n\n\n");
	display(L);
	//creating_display(L,0);
	}
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



// │ ─ ┌ ┐ └ ┘ ├ ┤ ┬ ┴ ┼ · 