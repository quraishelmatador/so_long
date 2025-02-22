/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars_in_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktayabal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:07:54 by ktayabal          #+#    #+#             */
/*   Updated: 2025/02/21 09:07:56 by ktayabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to check if there is only one 'P' in the map
int	check_player(char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
	{
		ft_perror("Error: There should be only one player in the map !\n");
		return (0);
	}
	return (1);
}

// function to check if there is only one 'E' in the map
int	check_exit(char **map)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1)
	{
		ft_perror("Error: There should be only one exit in the map !\n");
		return (0);
	}
	return (1);
}

// function to check if there is at least one 'C' in the map
int	check_collectibles(char **map)
{
	int	i;
	int	j;
	int	collectibles;

	i = 0;
	collectibles = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	if (collectibles == 0)
	{
		ft_perror("Error: There should be at least \
			one collectible in the map !\n");
		return (0);
	}
	return (1);
}

// function to check if map is rectangular
int	check_rectangular(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != len)
		{
			ft_perror("Error: Map is not rectangular !\n");
			return (0);
		}
		i++;
	}
	return (1);
}

// fucntion to check if there are only valid characters in the map
int	check_chars_in_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' \
				&& map[i][j] != 'E' && map[i][j] != 'C')
			{
				ft_perror("Error: Invalid character in the map !\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
