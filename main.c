/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktayabal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:55:45 by ktayabal          #+#    #+#             */
/*   Updated: 2025/02/20 21:55:47 by ktayabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(int argc, char **argv)
// {
// 	check_open_map(argc ,argv[1]);
// }

int	main(void)
{

	    char	**map;
	    t_point	player;
	
	    map = convert_to_matrix("map.ber");
	    player = find_player(map);
	    printf("Player position: x = %d, y = %d\n", player.x, player.y);
	    printf("WALLS: %i\n", check_walls(map));
	    free_matrix(map);
	    return (0);
}
