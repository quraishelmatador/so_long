#ifndef SO_LONG_H
# define SO_LONG_H

# include "include/Libft/libft.h"
# include "include/get_next_line/get_next_line.h"

# include <fcntl.h>
# include <stdio.h>


typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_point_list
{
	t_point			*point;
	struct s_point_list	*next;
}	t_point_list;

typedef struct t_queue
{
	t_point_list	*front;
	t_point_list	*rear;
}	t_queue;




// check_input.c
int	check_open_map(int argc, char *path);
int	check_args_and_name(int argc, char *path);
char	*find_map_path(char *path);

// map.c
char	*convert_to_str(char *path);
char	**convert_to_matrix(char *path);
void	free_matrix(char **matrix);
char	**map_dup(char **map);
t_point	find_player(char **map);

// check_chars_in_map.c
int	check_player(char **map);
int	check_exit(char **map);
int	check_collectibles(char **map);
int	check_rectangular(char **map);
int	check_chars_in_map(char **map);

// check_map.c
int	get_rows(char **map);
int	get_columns(char **map);
int	checkwalls_first_last_rows(char **map);
int	checkwalls_left_right_columns(char **map);
int	check_walls(char **map);

// checkpath.c
void	enqueue(t_queue *q, t_point *point);
t_point	*dequeue(t_queue *q);
t_point	*new_point(int x, int y);
int	flood_fill(char **map, t_point *player, int rows, int columns);

#endif