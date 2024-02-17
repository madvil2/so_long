/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:34:50 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/16 23:36:53 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(int x, int y, t_game *game, int *has_exit)
{
	if (game->map.map[x][y] == '1' || game->map.map[x][y] == 'e'
		|| game->map.map[x][y] == 'c' || game->map.map[x][y] == 'o'
		|| game->map.map[x][y] == 'p')
		return ;
	if (game->map.map[x][y] == 'E')
	{
		game->map.map[x][y] = 'e';
		*has_exit = 1;
	}
	if (game->map.map[x][y] == 'C')
	{
		game->map.map[x][y] = 'c';
		game->map.coins++;
	}
	if (game->map.map[x][y] == '0')
		game->map.map[x][y] = 'o';
	if (game->map.map[x][y] == 'P')
		game->map.map[x][y] = 'p';
	flood_fill(x + 1, y, game, has_exit);
	flood_fill(x - 1, y, game, has_exit);
	flood_fill(x, y + 1, game, has_exit);
	flood_fill(x, y - 1, game, has_exit);
}

int	flood_fill_check(t_game *game, int *has_exit)
{
	*has_exit = 0;
	flood_fill(game->player.y, game->player.x, game, has_exit);
	if (*has_exit != 1)
		return (0);
	return (1);
}
