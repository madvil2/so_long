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
	if (game->map[x][y] == '1' || game->map[x][y] == 'e'
		|| game->map[x][y] == 'c' || game->map[x][y] == 'o'
		|| game->map[x][y] == 'p')
		return ;
	if (game->map[x][y] == 'E')
	{
		game->map[x][y] = 'e';
		*has_exit = 1;
	}
	if (game->map[x][y] == 'C')
	{
		game->map[x][y] = 'c';
		game->coins++;
	}
	if (game->map[x][y] == '0')
		game->map[x][y] = 'o';
	if (game->map[x][y] == 'P')
		game->map[x][y] = 'p';
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
