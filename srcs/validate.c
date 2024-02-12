/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:17:41 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/12 22:03:45 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(char **map, int x, int y, t_game *game, int *has_exit)
{
	if (map[x][y] == '1' || map[x][y] == 'e' || map[x][y] == 'c' || map[x][y] == 'o' || map[x][y] == 'p')
		return;
	if (map[x][y] == 'E')
	{
		map[x][y] = 'e';
		*has_exit = 1;
	}
	if (map[x][y] == 'C')
	{
		map[x][y] = 'c';
		game->coins++;
	}
	if (map[x][y] == '0')
		map[x][y] = 'o';
	if (map[x][y] == 'P')
		map[x][y] = 'p';
	flood_fill(map, x + 1, y, game, has_exit);
	flood_fill(map, x - 1, y, game, has_exit);
	flood_fill(map, x, y + 1, game, has_exit);
	flood_fill(map, x, y - 1, game, has_exit);
}

int	flood_fill_check(char **map, t_game *game, int *has_exit)
{
	*has_exit = 0;
	flood_fill(map, game->player.x, game->player.y, game, has_exit);
	if (*has_exit != 1)
		return (0);
	return (1);
}

int	validate_map(char **map, t_game *game)
{
	int		has_exit;
	int		has_start;
	int		has_coins;

	if (!is_map_rectangular(map) || !is_surrounded_by_walls(map))
		return (free_map(map), 0);
	if (!validate_contents(map, &has_exit, &has_start, &has_coins, game)
		|| has_exit != 1 || has_coins < 1 || has_start != 1)
	{
		if (has_exit != 1)
			print_error(4);
		if (has_coins < 1)
			print_error(5);
		if (has_start != 1)
			print_error(6);
		free_map(map);
		return (0);
	}
	if (!flood_fill_check(map, game, &has_exit) || game->coins != has_coins)
		return (print_error(8), free_map(map), 0);
	return (1);
}