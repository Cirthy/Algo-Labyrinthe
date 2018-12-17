#ifndef			labyrinth_H
#define			labyrinth_H

#include		<stdio.h>
#include		<stdlib.h>
#include		<time.h>		// pour srand(tinme(NULL))
#include		<unistd.h>		// pour usleep()
#include 		<string.h>		// pour strcmp
#include 		<sys/ioctl.h>	// pour accéder a la taille du terminal


#define			WALL_PROB		3 // probabilité de mettre un mur lors de la génération aléatoire := 1 / WALL_PROB
#define			DISTANCE_MAX	4095 // 2**12 - 1
#define 		DISTANCE_MAX_BFS 2047 //2**11 - 1
#define			NO_PATH			-1 // Code à mettre dans path.length quand il n'y a pas de chemin
#define			PROFONDEUR		'p'
#define			LARGEUR			'l'
#define			LW				1
#define			BW				2
#define			RW				4
#define			TW				8

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



typedef struct		position
{
	int				x;
	int				y;	
}					position;

typedef	struct		labyrinth
{
	unsigned short	**grid;
	int				height;
	int				width;
	position		entrance;
	position		exit;
	position		cursor;
}					labyrinth;

typedef struct  	path
{
	char			type; // LARGEUR pour largeur, PROFONDEUR pour profondeur
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



// ===== generator.c =====
void	create_empty_lab(labyrinth *L, int height, int width);
void 	create_alea_lab(labyrinth *L, int height, int width);
void	init_wall(labyrinth *L);



// ===== display.c =====
void	display_lab_V1(labyrinth L);
void	display_lab_V2(labyrinth L, char mode, path* shortestPath);
void	init_displayer();
void	refresh_menu(labyrinth L, char mode, path* chemin);



// ===== menu.c =====
void 	home_menu(labyrinth *L);
void 	edit_menu(labyrinth *L);
void 	analysis_menu(labyrinth *L);



// ===== loadsave.c =====
void	load_file(labyrinth *L);
void	save_file(labyrinth *L);



// ===== management.c =====
	// Walls
char	left_wall(unsigned short cell);
char	bottom_wall(unsigned short cell);
char	right_wall(unsigned short cell);
char	top_wall(unsigned short cell);
char	is_wall(unsigned short cell, int dir);
	// Position
position pos(int x , int y);
char 	is_in_path(path *p, int x1, int y1, int x2, int y2);
int		actualize_distance(labyrinth L, position s1, position s2);
position pos_after_move(position pos, int dir);
int 	in_tab(position p, position* V, int size);
int 	pos_equal(position s1, position s2);
	// Distance
void	set_distance(labyrinth *L, position p, int distance);
void	init_distance(labyrinth *L);
void 	set_distances_to_zero(labyrinth *L);
int		get_distance(labyrinth *L, position p);
	// Other
unsigned short cell(labyrinth L, position p);
void	move_cursor(labyrinth *L, int dir);
position get_max_size_lab();
void	free_lab_grid(labyrinth *L);



// ===== pathfinding.c =====
path 	BFS(labyrinth L);
int 	is_marked (labyrinth L, position p);
path	pathfinding(labyrinth *L, char c);
void	browse_maze_DFS(labyrinth *L, int distance);
int		browse_maze_BFS(labyrinth *L, int distance, position *tab_pos);
path    construct_path(labyrinth *L, char type);
char 	can_go_there(labyrinth *L, char dir, int distance);
int		dir_adjacent_cell(labyrinth *L, position pos);


#endif