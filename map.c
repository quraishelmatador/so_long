/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktayabal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:22:16 by ktayabal          #+#    #+#             */
/*   Updated: 2025/02/20 22:22:18 by ktayabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*convert_to_str(char *path)
{
	int	fd;
	char	*map_path;
	char	*line;
	char	*str;
	char	*tmp;

	map_path = find_map_path(path);
	fd = open(map_path, O_RDONLY);
	free(map_path);
	if (fd < 0)
	{
		ft_perror("Error opening file !\n");
		return (NULL);
	}
	str = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = my_ft_strjoin(str, line);
		free(str);
		free(line);
		str = tmp;
		line = get_next_line(fd);
	}
	close(fd);
	return (str);	
}

char	**convert_to_matrix(char *path)
{
	char	*str;
	char	**matrix;

	str = convert_to_str(path);
	if (!str)
		return (NULL);
	matrix = ft_split(str, '\n');
	free(str);
	return (matrix);
}

char	**map_dup(char **map)
{
	char	**new_map;
	int	i;

	i = 0;
	while (map[i])
		i++;
	new_map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

// fucntion to find player position
t_point	find_player(char **map)
{
	t_point	player;
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player.x = j;
				player.y = i;
				return (player);
			}
			j++;
		}
		i++;
	}
	player.x = -1;
	player.y = -1;
	return (player);
}

