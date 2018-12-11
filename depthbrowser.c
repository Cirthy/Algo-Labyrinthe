#include    "labyrinthe.h"



char can_go_there(labyrinthe *L, char dir, int d)
{
    position next_cell;

    if(is_wall(L->grid[L->cursor.y][L->cursor.x], dir))
        return 0;
    next_cell.y = L->cursor.y + (dir==2) - (dir==8);
    next_cell.x = L->cursor.x + (dir==4) - (dir==1);
    return d < get_distance_12b(L, next_cell);
}


void parcour(labyrinthe *L, int d)
{
    if (can_go_there(L,1,d))
    {
        L->cursor.x--;
        set_distance(*L, L->cursor, d);
        parcour(L,d+1);
        L->cursor.x++;
    }
    if (can_go_there(L,2,d))
    {
        L->cursor.y++;
        set_distance(*L, L->cursor, d);
        parcour(L,d+1);
        L->cursor.y--;
    }
    if (can_go_there(L,4,d))
    {
        L->cursor.x++;
        set_distance(*L, L->cursor, d);
        parcour(L,d+1);
        L->cursor.x--;
    }
    if (can_go_there(L,8,d))
    {
        L->cursor.y--;
        set_distance(*L, L->cursor, d);
        parcour(L,d+1);
        L->cursor.y++;
    }
}

int min_dist_in_tab4(int *d)
{
    if (d[0]<= d[1] && d[0]<= d[2] && d[0]<= d[3])
        return 0;
    if (d[1]<= d[0] && d[1]<= d[2] && d[1]<= d[3])
        return 1;
    if (d[2]<= d[0] && d[2]<= d[1] && d[2]<= d[3])
        return 2;
    return 3;
}




path profondeur_baptiste(labyrinthe *L)
{
    init_distances(*L);

    L->cursor = L->entrance;

    parcour(L,1);


    path plusCourt;
    plusCourt.length = get_distance(*L, L->exit);
    plusCourt.cells = malloc((plusCourt.length+1) * sizeof(position));
    plusCourt.cells[0] = L->exit;

    int distance_voisine[4];
    position temp;
    //temp.x = 0;
    //temp.y = 0;
    //if (temp.x!=0)
    //    printf("X");

    for(int i = 1 ; i<plusCourt.length ; i++)
    {
        distance_voisine[0] = (left_wall(cell(*L,plusCourt.cells[i-1]))) ? L->height*L->width : L->grid[plusCourt.cells[i-1].y][plusCourt.cells[i-1].x-1] / 256;
        distance_voisine[1] = (bottom_wall(cell(*L,plusCourt.cells[i-1]))) ? L->height*L->width : L->grid[plusCourt.cells[i-1].y+1][plusCourt.cells[i-1].x] / 256;
        distance_voisine[2] = (right_wall(cell(*L,plusCourt.cells[i-1]))) ? L->height*L->width : L->grid[plusCourt.cells[i-1].y][plusCourt.cells[i-1].x+1] / 256;
        distance_voisine[3] = (top_wall(cell(*L,plusCourt.cells[i-1]))) ? L->height*L->width : L->grid[plusCourt.cells[i-1].y-1][plusCourt.cells[i-1].x] / 256;
        switch (min_dist_in_tab4(distance_voisine))
        {
            case 0: // case de distance d-1 a gauche
                temp.x = plusCourt.cells[i-1].x - 1;
                temp.y = plusCourt.cells[i-1].y; 
                break;
            case 1: // case de distance d-1 en bas
                temp.x = plusCourt.cells[i-1].x;
                temp.y = plusCourt.cells[i-1].y + 1;
                break;
            case 2: // case de distance d-1 a droite
                temp.x = plusCourt.cells[i-1].x + 1;
                temp.y = plusCourt.cells[i-1].y;
                break;
            case 3: // case de distance d-1 en haut
                temp.x = plusCourt.cells[i-1].x;
                temp.y = plusCourt.cells[i-1].y - 1; 
                break;
        }
        plusCourt.cells[i] = temp;
    }


    plusCourt.cells[plusCourt.length] = L->entrance;

    plusCourt.type = 'b';

    for(int tempi=0 ; tempi<L->height ; tempi++)
    {
		for(int tempj=0 ; tempj<L->width ; tempj++)
		{
			L->grid[tempi][tempj] %= 16 ;
		}
    }


    return plusCourt;

}