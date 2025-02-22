#ifndef SO_LONG_H
# define SO_LONG_H

# include "include/Libft/libft.h"
# include "include/get_next_line/get_next_line.h"

# include <fcntl.h>
# include <stdio.h>


typedef struct t_point
{
	int	x;
	int	y;
}	t_point;




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


#endif