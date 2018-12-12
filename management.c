#include	"labyrinthe.h"


char	left_wall(unsigned short cell)
{
	return cell % 2;
}


char	bottom_wall(unsigned short cell)
{
	return (cell / 2) % 2;
}


char	right_wall(unsigned short cell)
{
	return (cell / 4) % 2;
}


char	top_wall(unsigned short cell)
{
	return (cell / 8) % 2;
}

char	is_wall(unsigned short cell, int dir)
{
	return cell / dir % 2;
}


position pos(int x , int y)
{
	position temp;
	temp.x = x;
	temp.y = y;
	return temp;
}


char 	is_in_path(path *p, int x1, int y1, int x2, int y2)
{
	for (int i=0 ; i<=p->length ; i++)
	{
		if (p->cells[i].x == x1 && p->cells[i].y == y1)
		{
			if ((i==0 && p->cells[i+1].x == x2 && p->cells[i+1].y == y2) || (i==p->length && p->cells[i-1].x == x2 && p->cells[i-1].y == y2) || (p->cells[i+1].x == x2 && p->cells[i+1].y == y2) || (p->cells[i-1].x == x2 && p->cells[i-1].y == y2))
				return 1;
		}
	}
	return 0;
}


int 	set_distance(labyrinthe L, position p, int distance)
{
    L.grid[p.y][p.x] %= 256; // it remains the 8 least significant bits
    if (distance<=255)
    	L.grid[p.y][p.x] += distance * 256;
    else
    	L.grid[p.y][p.x] += 255 * 256;

    return 0;
}


void		set_distance_12b(labyrinthe *L, position p, int distance)
{
	L->grid[p.y][p.x] = L->grid[p.y][p.x] % 16 + distance * 16;
}


void		set_default_distance(labyrinthe *L)
{
	for(int i = 0 ; i < L->height ; i++)
		for(int j = 0 ; j < L->width ; j++)
			set_distance_12b(L, pos(j, i), DISTANCE_MAX);
	set_distance_12b(L, L->entrance, 0);
}

void        set_distances_to_zero(labyrinthe *L)
{
    for(int i=0 ; i<L->height ; i++)
        for( int j=0 ; j<L->width ; j++)
            L->grid[i][j] %= 16;
}


int 		get_distance(labyrinthe L, position p)
{
    return L.grid[p.y][p.x] / 256;
}

int			get_distance_12b(labyrinthe *L, position p)
{
	return L->grid[p.y][p.x] / 16;
}

int 		init_distances(labyrinthe L) {
    int i;
    int j;
    position tmp;
    for(i = 0 ; i < L.height ; i++) {
        for(j = 0 ; j < L.width ; j++) {
            if ( (i != L.entrance.y) || (j != L.entrance.x) ) {        // distance entrance/entrance = 0
                tmp.x = j;
                tmp.y = i;
                set_distance(L, tmp, L.height * L.width);    // "infinite" = height * width (the distances never exceeds that)
            }
        }
    }
    return 0;
}


int 		actualize_distance(labyrinthe L, position s1, position s2) {
    if ( get_distance(L, s1) + 1 < get_distance(L, s2) ) {
        set_distance(L, s2, get_distance(L, s1)+1);
        return 1;    // distance actualized
    }
    return 0;    // s1 is not a good way to access to s2
}


void		move_cursor(labyrinthe *L, int dir)
{
	L->cursor.x += (dir == 4) - (dir == 1);
	L->cursor.y += (dir == 2) - (dir == 8);
}


position	pos_after_move(position p, int dir)
{
	return pos(p.x + (dir == 4) - (dir == 1), p.y + (dir == 2) - (dir == 8));
}


unsigned int cell(labyrinthe L, position p) 
{
    return L.grid[p.y][p.x];
}


int			in_tab(position p, position* V, int size) 
{
    int i;
    for (i=0; i<size; i++) {
        if (V[i].x == p.x && V[i].y == p.y) {
            return i;    // p is in T at the index i
        }
    }
    printf("(%d, %d) not in V\n", p.x, p.y);
    return -1; // p is not in T
}


int			pos_equal(position s1, position s2)
{
    return (s1.x == s2.x) && (s1.y == s2.y) ? 1 : 0;
}