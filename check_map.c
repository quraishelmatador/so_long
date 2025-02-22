/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktayabal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:16:53 by ktayabal          #+#    #+#             */
/*   Updated: 2025/02/21 09:16:54 by ktayabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to get rows count im map
int	get_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

// function to get columns count in map
int	get_columns(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	return (j);
}

// function to check if first and last line are '1'
int	checkwalls_first_last_rows(char **map)
{
	int	rows;
	int	i;

	rows = get_rows(map);
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
		{
			ft_perror("Error:\n First line should be '1' !\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (map[rows - 1][i])
	{
		if (map[rows-1][i] != '1')
		{
			ft_perror("Error:\n Last line should be '1' !\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	checkwalls_left_right_cols(char **map)
{
	int	columns;
	int	i;

	columns = get_columns(map);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
		{
			ft_perror("Error:\n First column should be '1' !\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][columns - 1] != '1')
		{
			ft_perror("Error:\n Last column should be '1' !\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	if (checkwalls_first_last_rows(map) == 0)
		return (0);
	if (checkwalls_left_right_cols(map) == 0)
		return (0);
	return (1);
}
