#ifndef			LABYRINTHE_H
#define			LABYRINTHE_H

#include		<stdio.h>
#include		<stdlib.h>
#include		<time.h>		//pour srand(tinme(NULL))
#include		<unistd.h>		//pour usleep()
#include 		<string.h>		//pour strcmp

#define			WALL_PROB		3 //probabilité de mettre un mur lors de la géné := 1 / WALL_PROB

//outil de mise en forme coloré

#define 		set_color(att, fg) 	printf("\033[%d;%dm", att, fg + 30)

#define 		RESET			0
#define 		DEFAULT			0
#define 		BLOOD 			1
#define			ITALIC			3  // italique
#define 		UNDERLINE 		4
#define 		WINKER 			5  // clignotant
#define 		REVERSE			7


#define 		BLACK 			0
#define 		RED				1
#define 		GREEN			2
#define 		YELLOW			3
#define 		BLUE			4
#define 		MAGENTA			5
#define 		CYAN			6
#define 		LIGHT_GREY 		7
#define			WHITE			8


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
	char			type;
	int				length;
	position		*cells;
}					path;

char* dragon[15];
position pos_dragon;
char* knight[10];
position pos_knight;
char* lab[6];
position pos_lab;
char* oratoire[6];
position pos_oratoire;







void	init_lab(labyrinthe *L, int lab_height, int lab_width);
void	create_lab(labyrinthe *L, int lab_height, int lab_width);
void	init_wall(labyrinthe L);
char	left_wall(unsigned short cell);
char	bottom_wall(unsigned short cell);
char	right_wall(unsigned short cell);
char	top_wall(unsigned short cell);
char 	is_in_path(path *p, int x1, int y1, int x2, int y2);

void	temp_display(labyrinthe L);
void	display(labyrinthe L);
void	displayV2(labyrinthe L, char mode, path* plusCourt);
void	creating_display(labyrinthe L, int half);
void	create_lab(labyrinthe *L, int lab_height, int lab_width);
void 	edit_lab(labyrinthe *L);
void 	analyse_menu(labyrinthe *L);
void	init_displayer();
void	menu_display(labyrinthe L, char mode, path* chemin);

void 	menu(labyrinthe* L);

void	read_file(labyrinthe *L);
void	save_file(labyrinthe *L);




void 	display_path(path* chemin);


// pathfinding
int		set_distance(labyrinthe L, position p, int distance);
int		distance(labyrinthe L, position p);
int		init_distances(labyrinthe L);
int		actualize_distance(labyrinthe L, position s1, position s2);
unsigned int cell(labyrinthe L, position p);
int 	mark (labyrinthe L, position p);
int 	is_marked (labyrinthe L, position p);
int 	in_tab(position p, position* V, int size);
int 	pos_equal(position s1, position s2);
position copy_pos(position s);
int 	display_pos(position p);
int 	display_tab(position* T, int size_T);
path 	BFS(labyrinthe L);


void	display_marked(labyrinthe L);
void	display_visit_order(labyrinthe L, position *V);

#endif
