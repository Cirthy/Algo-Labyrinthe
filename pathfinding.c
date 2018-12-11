#include	"labyrinthe.h"



/* Breadth-first search
____________________________________________________________________________________________*/


int mark (labyrinthe L, position p) {
    if ( is_marked(L, p) == 0 ) {
        L.grid[p.y][p.x] += 16;
    }
    return 0;
}


int is_marked (labyrinthe L, position p) {
    return ( (L.grid[p.y][p.x] / 16) % 2);
} // 1 if marked ; 0 if not


path BFS(labyrinthe L) {
    init_distances(L);

    int size_V = L.height * L.width;
	position* V = malloc(size_V * sizeof(position));    // order of visit of the vertex
    position* P = malloc(size_V * sizeof(position));    // P[i] predecessor of V[i]


    /*** initialization of V and P with positions (-1, -1) ***/
    position pos_null;
    pos_null.x = -1;
    pos_null.y = -1;

    int i;
    for (i=0; i< size_V; i++) {
        V[i] = pos_null;
        P[i] = pos_null;
    }
    V[0] = L.entrance;
    mark(L, L.entrance);



    int V_index = 1;    // index of adding elements in the tables V and P
    int V_visit = 0;    // index of the visited vertex (table V)

    position visited;
    position next;

    while ( ( V_index != V_visit ) && ( pos_equal(V[V_visit], L.exit) == 0)) {

        visited = V[ V_visit ];
        if ( left_wall( cell(L, visited) ) == 0 ) {    // if there is no left wall
            next.y = visited.y;
            next.x = visited.x - 1;
            if (is_marked(L, next) == 0) {    // cell not marked
                actualize_distance(L, visited, next);    // distance(next) := distance(visited) + 1
                V[ V_index ] = next;        // add next at the table of vertex to visit
                P[ V_index ] = visited;        // "next" predecessor := visited
                V_index ++;                 // indice to add the next cell after this one
                mark(L, next);                  
            }
        } // end if left_wall

        if ( bottom_wall( cell(L, visited) ) == 0 ) {    // if there is no bottom wall
            next.y = visited.y + 1;
            next.x = visited.x;
            if (is_marked(L, next) == 0) {
                actualize_distance(L, visited, next);
                V[ V_index ] = next;
                P[ V_index ] = visited;
                V_index ++;
                mark(L, next);
            }
        } // bottom

        if ( right_wall( cell(L, visited) ) == 0 ) {    // if there is no right wall
            next.y = visited.y;
            next.x = visited.x + 1;
            if (is_marked(L, next) == 0) {
                actualize_distance(L, visited, next);
                V[ V_index ] = next;
                P[ V_index ] = visited;
                V_index ++;
                mark(L, next);
            }
        } // right

        if ( top_wall( cell(L, visited) ) == 0 ) {    // if there is no top wall
            next.y = visited.y - 1;
            next.x = visited.x ;
            if (is_marked(L, next) == 0) {
                actualize_distance(L, visited, next);
                V[ V_index ] = next;
                P[ V_index ] = visited;
                V_index ++;
                mark(L, next); 
            }
        } // top
   // avoid loops and regresses
        V_visit ++;



    } // end while


    /*** Find the way backwards ***/

    int distance_shortest_path = get_distance(L, L.exit) ;
    position* shortest_path;    // AMELIORATION POSSIBLE : STRUCTURE LISTE CHAÎNEE
    shortest_path = malloc( (distance_shortest_path +1) * sizeof(position));    // (+1) for the entrance

    int index_shortest_path = distance_shortest_path;    // course of the table shortest_path from the end

    int index_pos;    // index to retrieve positions in V and P
    index_pos = in_tab(L.exit, V, size_V);    // initialize index_pos at the index of L.exit in the table V ; -1 if L.exit is not in V

    if (index_pos == -1) {
        printf("Il n'y a pas de chemin entre l'entree et la sortie du labyrinthe.\n");
    } else {

        // METTRE PREDECESSEUR ENTREE A -2 -2
        while ( index_pos != 0 ) {    // stop condition = no predecessor <=> the entrance has been added to shortest_path
            //printf("index_pos : %d\n", index_pos);
            shortest_path[ index_shortest_path ] = V[ index_pos ];
            index_shortest_path--;

            index_pos = in_tab(P[ index_pos ], V, size_V);
            }    // A VERIFIER
        shortest_path[0] = V[0];    // add the entrance


        /*** display the liste ***/
        //display_tab(shortest_path, distance_shortest_path +1);


        }

    free(V);
    free(P);

    path Path;
    Path.length = distance_shortest_path;
    Path.cells = shortest_path;
    Path.type = 'l';

    for(int tempi=0 ; tempi<L.height ; tempi++)
    {
		for(int tempj=0 ; tempj<L.width ; tempj++)
		{
			L.grid[tempi][tempj] %= 16 ;
		}
    }



    return Path;

} // end BFS


/* Depth First Search
____________________________________________________________________________________________*/


char can_go_there(labyrinthe *L, char dir, int d) // 1 si le curseur peut se déplacer selon direction, 0 sinon
{
    position next_cell;

    if(is_wall(L->grid[L->cursor.y][L->cursor.x], dir))
        return 0;
    next_cell.y = L->cursor.y + (dir==2) - (dir==8);
    next_cell.x = L->cursor.x + (dir==4) - (dir==1);
    return d < get_distance_12b(L, next_cell);
}


int		dir_adjacent_cell(labyrinthe *L, position pos) // Donne la direction d'une cellule accessible adjacente plus proche de l'entrée
{
	for(int dir = 1 ; dir <= 8 ; dir *= 2)
		if((get_distance_12b(L, pos_after_move(pos, dir)) == get_distance_12b(L, pos) - 1) && !is_wall(L->grid[pos.y][pos.x], dir))
			return dir;
	return 0;
}


void	browse_maze(labyrinthe *L, int distance) // Parcourt le labyrinthe et calcule la distance à l'entrée de TOUTES les cases
{
	if(pos_equal(L->cursor, L->exit) || distance == DISTANCE_MAX)
		return;
	for(int dir = 1 ; dir <= 8 ; dir *= 2)
		if(can_go_there(L, dir, distance + 1))
		{
			move_cursor(L, dir);
			set_distance_12b(L, L->cursor, distance + 1);
			browse_maze(L, distance + 1);
			move_cursor(L, dir * 4 % 15);
		}
}


path	DFS(labyrinthe *L) // Renvoie un plus court chemin de l'entrée vers la sortie
{
	path		path;
	position	current_pos;

	path.type = 'p';
	set_default_distance(L);
	L->cursor = L->entrance;
	browse_maze(L, 0);
	if(get_distance_12b(L, L->exit) == DISTANCE_MAX && !dir_adjacent_cell(L, L->exit)) // On gère le cas où la sortie est à DISTANCE_MAX de l'entrée
	{
		path.length = NO_PATH;
		path.cells = NULL;
		return path; // Pas de chemin de longueur <= DISTANCE_MAX
	}
	path.cells = (position*)malloc(sizeof(position) * (get_distance_12b(L, L->exit) + 1));
	path.length = get_distance_12b(L, L->exit) + 1;
	current_pos = L->exit;
	path.cells[0] = current_pos; // LA tableau des pos commence par la sortie
	for(int i = 0 ; i < get_distance_12b(L, L->exit) ; i++)
	{
		current_pos = pos_after_move(current_pos, dir_adjacent_cell(L, current_pos));
		path.cells[i] = current_pos;
		display_position(current_pos);
		printf("\t%d\n", i);
	}
	return path;
}
