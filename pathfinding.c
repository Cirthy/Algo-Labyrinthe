#include	"labyrinthe.h"


path	search_path_depth(labyrinthe *L)
{
	path		path;
	position	current_pos;

	path.type = 'p';
	set_default_distance(L);
	L->cursor = L->entrance;
	browse_maze(L, 0);
	display_distance(L);
	if(get_distance_12b(L, L->exit) == DISTANCE_MAX && !dir_adjacent_cell(L, L->exit))
	{
		path.length = -1;
		path.cells = NULL;
		return path;
	}
	path.cells = (position*)malloc(sizeof(position) * (get_distance_12b(L, L->exit) + 1));
	path.length = get_distance_12b(L, L->exit) + 1;
	current_pos = L->exit;
	path.cells[0] = current_pos;
	for(int i = 0 ; i < get_distance_12b(L, L->exit) ; i++)
	{
		current_pos = pos_after_move(current_pos, dir_adjacent_cell(L, current_pos));
		path.cells[i] = current_pos;
		display_position(current_pos);
		printf("\t%d\n", i);
	}
	return path;
}


int		dir_adjacent_cell(labyrinthe *L, position pos)
{
	for(int dir = 1 ; dir <= 8 ; dir *= 2)
		if((get_distance_12b(L, pos_after_move(pos, dir)) == get_distance_12b(L, pos) - 1) && !is_wall(L->grid[pos.y][pos.x], dir))
			return dir;
	return 0;
}


void	browse_maze(labyrinthe *L, int distance)
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
