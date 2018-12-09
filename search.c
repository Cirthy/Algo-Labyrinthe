// search.c

#include    "labyrinthe.h"


int set_distance(labyrinthe L, position p, int distance) {
    L.grid[p.y][p.x] %= 256; // it remains the 8 least significant bits
    if (distance<=255)
    	L.grid[p.y][p.x] += distance * 256;
    else
    	L.grid[p.y][p.x] += 255 * 256;

    return 0;
}

int distance(labyrinthe L, position p) {
    return L.grid[p.y][p.x] / 256;
}





/*** A FAIRE
init distance à 11111111
test actu distances si >= 128***/
int init_distances(labyrinthe L) {
    int i;
    int j;
    position tmp;
    for(i = 0 ; i < L.lab_height ; i++) {
        for(j = 0 ; j < L.lab_width ; j++) {
            if ( (i != L.pos_entrance.y) || (j != L.pos_entrance.x) ) {        // distance entrance/entrance = 0
                tmp.x = j;
                tmp.y = i;
                set_distance(L, tmp, L.lab_height * L.lab_width);    // "infinite" = height * width (the distances never exceeds that)
            }
        }
    }
    return 0;
}

//18.04.1
int actualize_distance(labyrinthe L, position s1, position s2) {
    if ( distance(L, s1) + 1 < distance(L, s2) ) {
        set_distance(L, s2, distance(L, s1)+1);
        return 1;    // distance actualized
    }
    return 0;    // s1 is not a good way to access to s2
}



unsigned int cell(labyrinthe L, position p) {
    return L.grid[p.y][p.x];
}

int mark (labyrinthe L, position p) {
    if ( is_marked(L, p) == 0 ) {
        L.grid[p.y][p.x] += 16;
    }
    return 0;
}

int is_marked (labyrinthe L, position p) {
    return ( (L.grid[p.y][p.x] / 16) % 2);
} // 1 if marked ; 0 if not



int in_tab(position p, position* V, int size) {
    int i;
    for (i=0; i<size; i++) {
        if (V[i].x == p.x && V[i].y == p.y) {
            return i;    // p is in T at the index i
        }
    }
    printf("(%d, %d) not in V\n", p.x, p.y);
    return -1; // p is not in T
}


int pos_equal(position s1, position s2) {
    return (s1.x == s2.x) && (s1.y == s2.y) ? 1 : 0;
}

position copy_pos(position s) {
    position p;
    p.x = s.x;
    p.y = s.y;
    return p;
}


int display_pos(position p) {
    printf("(%d, %d)\n", p.x, p.y);
    return 0;
}

int display_tab(position* T, int size_T) {
    int i;
    for (i=0; i<size_T; i++) {
        printf("%d : ", i);
        display_pos(T[i]);
    }
    printf("\n");
    return 0;
}


path BFS(labyrinthe L) {
    init_distances(L);

    int size_V = L.lab_height * L.lab_width;
	position* V = malloc(size_V * sizeof(position));    // order of visit of the vertex
    position* P = malloc(size_V * sizeof(position));    // P[i] predecessor of V[i]


    /*** initialization of V and P with positions (-1, -1) ***/
    position pos_null;
    pos_null.x = -1;
    pos_null.y = -1;

    int i;
    for (i=0; i< size_V; i++) {
        V[i] = copy_pos(pos_null);
        P[i] = copy_pos(pos_null);
    }
    V[0] = L.pos_entrance;
    mark(L, L.pos_entrance);



    int V_index = 1;    // index of adding elements in the tables V and P
    int V_visit = 0;    // index of the visited vertex (table V)

    position visited;
    position next;

    while ( ( V_index != V_visit ) && ( pos_equal(V[V_visit], L.pos_exit) == 0)) {

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

    int distance_shortest_path = distance(L, L.pos_exit) ;
    position* shortest_path;    // AMELIORATION POSSIBLE : STRUCTURE LISTE CHAÎNEE
    shortest_path = malloc( (distance_shortest_path +1) * sizeof(position));    // (+1) for the entrance

    int index_shortest_path = distance_shortest_path;    // course of the table shortest_path from the end

    int index_pos;    // index to retrieve positions in V and P
    index_pos = in_tab(L.pos_exit, V, size_V);    // initialize index_pos at the index of L.pos_exit in the table V ; -1 if L.pos_exit is not in V

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
        shortest_path[0] = copy_pos(V[0]);    // add the entrance


        /*** display the liste ***/
        //display_tab(shortest_path, distance_shortest_path +1);


        }

    printf("avant free\n");

    //free(V);
    //free(P);

    printf("apres free\n");
    path Path;
    Path.length = distance_shortest_path;
    Path.cells = shortest_path;
    Path.type = 'l';

    for(int tempi=0 ; tempi<L.lab_height ; tempi++)
    {
		for(int tempj=0 ; tempj<L.lab_width ; tempj++)
		{
			L.grid[tempi][tempj] %= 16 ;
		}
    }



    return Path;

} // end BFS
