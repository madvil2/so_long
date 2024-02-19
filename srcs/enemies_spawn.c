/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_spawn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:59:45 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/19 01:00:20 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	calculate_enemies(int width, int height)
{
	int	perimeter;
	int	enemies;

	perimeter = 2 * (width + height);
	enemies = perimeter / 20;
	return (enemies > 0 ? enemies : 1);
}

void	spawn_enemy(t_game *game, int x, int y)
{
	int	enemies;
	int	i;
	int	j;
	int	k;

	j = game->map.height - 2;
	k = game->map.width - 2;

	i = 0;
	enemies = calculate_enemies(game->map.width, game->map.height);
	game->enemies = (t_bot *)malloc((enemies) * sizeof(t_bot));
	while (j > 0)
	{
		while (k > 0)
		{
			if (game->map.map[j][k] == 'o')
			{
				if (i >= enemies)
					break ;
				mlx_put_image_to_window(game->mlx, game->window, game->textures.enemy, k * 32, j * 32);
				game->enemies[i].x = j;
				game->enemies[i].y = k;
				game->enemies[i].orient = 'U';
				game->map.enemies_count++;
				i++;
			}
			k--;
		}
		j--;
	}
}