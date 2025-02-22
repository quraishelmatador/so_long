/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktayabal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:55:36 by ktayabal          #+#    #+#             */
/*   Updated: 2025/02/20 22:04:06 by ktayabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*find_map_path(char *path)
{
	return (my_ft_strjoin("maps/", path));
}

int	check_open_map(int argc, char *path)
{
	int			fd;
	char		*map_path;

	if (check_args_and_name(argc, path) == 0)
		return (0);
	map_path = find_map_path(path);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		perror("int check_map(char *path) Error opening map");
		return (0);
	}
	close(fd);
	free(map_path);
	return (1);
}

int	check_args_and_name(int argc, char *path)
{
	int	l;

	if (argc != 2)
	{
		ft_perror("ERROR: The program takes ONE argument !\n");
		return (0);
	}
	l = ft_strlen(path) - 1;
	if (path[l] != 'r' || path[l - 1] != 'e' || \
		path[l - 2] != 'b' || path[l - 3] != '.')
	{
		ft_perror("ERROR: Map file must be *.ber !\n");
		return (0);
	}
	return (1);
}
