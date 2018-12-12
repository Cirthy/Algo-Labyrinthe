#ifndef			LABYRINTHE_H
#define			LABYRINTHE_H

#include		<stdio.h>
#include		<stdlib.h>
#include		<time.h>		// pour srand(tinme(NULL))
#include		<unistd.h>		// pour usleep()
#include 		<string.h>		// pour strcmp

#define			WALL_PROB		3 // probabilité de mettre un mur lors de la génération aléatoire := 1 / WALL_PROB
#define			DISTANCE_MAX	4095 // 2**12 - 1
#define			NO_PATH			-1 // Code à mettre dans path.length quand il n'y a pas de chemin


// outil de mise en forme coloré
#define 		set_color(att, fg) 	printf("\033[%d;%dm", att, fg + 30)

#define 		RESET			0
#define 		DEFAULT			0
#define 		BLOOD 			1  // gras
#define			ITALIC			3  // italique
#define 		UNDERLINE 		4  // souligné
#define 		WINKER 			5  // clignotant
#define 		REVERSE			7  // négatif


#define 		BLACK 			0
#define 		RED				1
#define 		GREEN			2
#define 		YELLOW			3
#define 		BLUE			4
#define 		MAGENTA			5
#define 		CYAN			6
#define 		LIGHT_GREY 		7
#define			WHITE			8
// __________________________________________________________


enum wall { LW = 1, BW = 2, RW = 4, TW = 8 };


typedef struct		position
{
	int				x;
	int				y;	
}					position;

typedef	struct		labyrinthe
{
	unsigned short	**grid;
	int				height;
	int				width;
	position		entrance;
	position		exit;
	position		cursor;
}					labyrinthe;

typedef struct  	path
{
	char			type; // 'l' pour largeur, 'h' pour largeur avec heuristique, 'p' pour profondeur
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



// generator.c
void	create_empty_lab(labyrinthe *L, int height, int width);
void 	create_alea_lab(labyrinthe *L, int height, int width);
void	init_wall(labyrinthe *L);



// display.c
void	display_lab_V1(labyrinthe L);
void	display_lab_V2(labyrinthe L, char mode, path* plusCourt);
void 	display_path(path* chemin);
void	display_marked(labyrinthe L);
void	display_visit_order(labyrinthe L, position *V);
void	display_menu(labyrinthe L, char mode, path* chemin);
void 	display_position(position p);
void 	display_positions_tab(position* T, int size_T);
void	init_displayer();
void	display_distance(labyrinthe *L);



// menu.c
void 	home_menu(labyrinthe* L);
void 	edit_menu(labyrinthe *L);
void 	analysis_menu(labyrinthe *L);



// loadsave.c
void	load_file(labyrinthe *L);
void	save_file(labyrinthe *L);




// management.c
char	left_wall(unsigned short cell);
char	bottom_wall(unsigned short cell);
char	right_wall(unsigned short cell);
char	top_wall(unsigned short cell);
char	is_wall(unsigned short cell, int dir);
position pos(int x , int y);
char 	is_in_path(path *p, int x1, int y1, int x2, int y2);
int		set_distance(labyrinthe L, position p , int distance);
int		get_distance(labyrinthe L, position p);
int		init_distances(labyrinthe L);
int		actualize_distance(labyrinthe L, position s1, position s2);
unsigned int cell(labyrinthe L, position p);
int 	in_tab(position p, position* V, int size);
int 	pos_equal(position s1, position s2);
void	set_distance_12b(labyrinthe *L, position p, int distance);
void	set_default_distance(labyrinthe *L);
void 	set_distances_to_zero(labyrinthe *L);
int		get_distance_12b(labyrinthe *L, position p);
void	move_cursor(labyrinthe *L, int dir);
position pos_after_move(position pos, int dir);



/* depthbrowser.c
void 	parcour(labyrinthe *L, int d);
int 	min_dist_in_tab4(int *d);
path 	profondeur_baptiste(labyrinthe *L);*/



//pathfinding.c
int 	mark (labyrinthe L, position p);
int 	is_marked (labyrinthe L, position p);
path 	BFS(labyrinthe L);

char 	can_go_there(labyrinthe *L, char dir, int d);
int		dir_adjacent_cell(labyrinthe *L, position pos);
void	browse_maze(labyrinthe *L, int distance);
path	DFS(labyrinthe *L);



#endif