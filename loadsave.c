#include "labyrinth.h"

void save_file(labyrinth *L)
{
	char name_file[100]="";

	printf("\r   (-m- pour retourner au menu) Nom du fichier de sauvegarde ? ");
	scanf("%s",name_file);
	if(strcmp(name_file,"m") == 0)
		return;
	else
	{
		FILE* file = NULL;
		file = fopen(name_file,"w");

		//on vérifie que le fichier est bien créé
		if(file == NULL)
			printf("   Impossible de créer le fichier %s.",name_file);
		else
		{
			//on inscrit les informations générales sur de la 1ère ligne
			fprintf(file, "%2d %2d ", L->height, L->width);				//taille du labyrinthe : hauteur largeur
			fprintf(file, "%2d %2d ", L->entrance.y, L->entrance.x);	//position de l'entrée : ligne colonne
			fprintf(file,"%2d %2d \n", L->exit.y, L->exit.x);			//position de la sortie : ligne colonne

			for(int i=0; i<(L->height); i++)
			{
				for(int j=0; j<(L->width); j++)
					fprintf(file, "%2hu ", (L->grid)[i][j]);			//valeur de la cellule de position (j,i)
				fprintf(file, "\n");									// i=numéro de ligne et j=numéro de colonne
			}
		}

		fclose(file);
		printf("   labyrinthe sauvegardé avec succès.\n");				// on notifie que la sauvegarde s'est bien déroulée
		//scanf("%s",name_file);
		usleep(1200000);
	}	
}


void load_file(labyrinth *L)
{
	char name_file[100]="";

	FILE* file = NULL;
	
	//on demande le nom du fichier à ouvrir et on vérifie qu'il s'est bien ouvert
	while(file == NULL)
	{
		printf("   (-m- pour retourner au menu) Quel fichier souhaiter vous charger ? ");
		scanf("%s",name_file);
		if(strcmp(name_file,"m") == 0)
			return;
		else
			file = fopen(name_file,"r");
		if (file == NULL)
			printf("      Impossible d'ouvrir le fichier %s.\n",name_file);
	}




	//on récupère les informations de la 1ère ligne	
	fscanf(file, "%d ", &L->height);		//hauteur du labyrinth
	fscanf(file, "%d ", &L->width);			//largeur du labyrinth
	fscanf(file, "%d ", &L->entrance.y);
	fscanf(file, "%d ", &L->entrance.x);	//position de l'entrée : ligne colonne
	fscanf(file, "%d ", &L->exit.y);
	fscanf(file, "%d", &L->exit.x);			// position de la sortie : ligne colonne

	L->grid = (unsigned short **)malloc(sizeof(unsigned short *) * L->height);
	for(int i = 0 ; i < L->height ; i++)
		(L->grid)[i] = (unsigned short *)calloc(sizeof(unsigned short), L->width);

	for(int i=0; i<L->height; i++)
	{
		for(int j=0; j<(L->width); j++)
		{
			fscanf(file, "%hu", &(L->grid)[i][j]);	// valeur de la cellule de position (j,i) i=numéro de ligne et j=numéro de colonne
		}
	}

	fclose(file);

	
}
