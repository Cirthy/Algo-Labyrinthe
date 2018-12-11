// search.c

#include    "labyrinthe.h"







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
