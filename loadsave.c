#include "labyrinthe.h"

void save_file(labyrinthe *L)
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

		if(file == NULL)
			printf("   Impossible de créer le fichier %s.",name_file);
		else
		{
			//on inscrit les informations générales sur de la 1ère ligne
			fprintf(file, "%2d %2d ", L->height, L->width);
			fprintf(file, "%2d %2d ", L->entrance.x, L->entrance.y);
			fprintf(file,"%2d %2d \n", L->exit.x, L->exit.y);

			for(int i=0; i<(L->height); i++)
			{
				for(int j=0; j<(L->width); j++)
					fprintf(file, "%2hu ", (L->grid)[i][j]);
				fprintf(file, "\n");
			}
		}

		fclose(file);
		printf("   Labyrinthe sauvegardé avec succes.\n");
		//scanf("%s",name_file);
		usleep(1200000);
	}	
}


void load_file(labyrinthe *L)
{
	char name_file[100]="";

	FILE* file = NULL;
	

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
	fscanf(file, "%d ", &L->height);	
	fscanf(file, "%d ", &L->width);
	fscanf(file, "%d ", &L->entrance.x);
	fscanf(file, "%d ", &L->entrance.y);
	fscanf(file, "%d ", &L->exit.x);
	fscanf(file, "%d", &L->exit.y);

	L->grid = (unsigned short **)malloc(sizeof(unsigned short *) * L->height);
	for(int i = 0 ; i < L->height ; i++)
		(L->grid)[i] = (unsigned short *)calloc(sizeof(unsigned short), L->width);

	for(int i=0; i<L->height; i++)
	{
		for(int j=0; j<(L->width); j++)
		{
			fscanf(file, "%hu", &(L->grid)[i][j]);
		}
	}

	fclose(file);

	
}
