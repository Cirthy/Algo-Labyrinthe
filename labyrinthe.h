#ifndef				LABYRINTHE_H
#define				LABYRINTHE_H

#include			<stdio.h>
#include			<stdlib.h>
#include			<time.h>		//pour srand(tinme(NULL))
#include			<unistd.h>		//pour usleep()
#include 			<string.h>		//pour strcmp

#define				WALL_PROB		3 //probabilité de mettre un mur lors de la géné := 1 / WALL_PROB

//outil de mise en forme coloré
/*#define				set_color(param) 	printf("\033[%sm",param)
#define 			BLOOD 			"1"  // gras
#define 			ITALIC			"3"  // italique
#define				UNDER			"4"  // souligné
#define 			WINKER 			"5"  // clignotant
#define 			DEFAULT 		"0"  // par défaut
#define 			GREEN 			"32" // vert
#define 			BLUE 			"34" // bleu
#define 			CYAN 		 	"36" // cyan
#define 			RED 			"31" // rouge
#define 			MAGENTA			"35" // magenta
#define 			YELLOW 			"14" // jaune
#define 			BROWN 			"33" // marron
*/

#define 			set_color(att, fg) printf("\033[%d;%dm", att, fg + 30)

#define RESET		0
#define DEFAULT		0
#define BLOOD 		1
#define 			ITALIC			3  // italique
#define UNDERLINE 	4
#define 			WINKER 			5  // clignotant
#define REVERSE		7


#define BLACK 		0
#define RED			1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define LIGHT_GREY 	7
#define	WHITE		8






char* dragon[15];
char* knight[10];
char* lab[6];
char* oratoire[6];


enum { LW = 1, BW = 2, RW = 4, TW = 8 };

typedef struct		position
{
	int				x;
	int				y;	
}					position;

typedef	struct		labyrinthe
{
	unsigned short	**grid;
	int				lab_height;
	int				lab_width;
	position		pos_entrance;
	position		pos_exit;
	position		cursor;
}					labyrinthe;

typedef struct  	path
{
	struct path 	*precedent;
	position		actuel;
	struct path		*suivant;
}					path;



void	init_lab(labyrinthe *L, int lab_height, int lab_width);
void	create_lab(labyrinthe *L, int lab_height, int lab_width);
void	init_wall(labyrinthe L);
char	left_wall(unsigned short cell);
char	bottom_wall(unsigned short cell);
char	right_wall(unsigned short cell);
char	top_wall(unsigned short cell);
void	temp_display(labyrinthe L);
void	display(labyrinthe L);
void	displayV2(labyrinthe L);
void	creating_display(labyrinthe L, int half);
void	create_lab(labyrinthe *L, int lab_height, int lab_width);
void	init_displayer();
void	menu_display(labyrinthe L, char mode, position pos_dragon, position pos_knight, position pos_lab, position pos_oratoire);

void 	menu(labyrinthe* L);

void	read_file(labyrinthe *L);
void	save_file(labyrinthe *L);





#endif
