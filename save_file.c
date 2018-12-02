#include "labyrinthe.h"

void save_file(labyrinthe *L)
{
	char name_file[100]="";

	printf("\r   (-m- pour retourner au menu) Nom du fichier de sauvegarde ? ");
	scanf("%s",name_file);

	FILE* file = NULL;
	file = fopen(name_file,"w");

	if(file == NULL)
		printf("   Impossible de créer le fichier %s.",name_file);
	else
	{
		//on inscrit les informations générales sur de la 1ère ligne
		fprintf(file, "%2d %2d ", L->lab_height, L->lab_width);
		fprintf(file, "%2d %2d ", L->pos_entrance.x, L->pos_entrance.y);
		fprintf(file,"%2d %2d \n", L->pos_exit.x, L->pos_exit.y);

		for(int i=0; i<(L->lab_height); i++)
		{
			for(int j=0; j<(L->lab_width); j++)
				fprintf(file, "%2hu ", (L->grid)[i][j]);
			fprintf(file, "\n");
		}
	}

	fclose(file);
	printf("   Labyrinthe sauvegarder avec succes.");
	scanf("%s",name_file);

	
}
