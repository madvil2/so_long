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

void	enemy_logic(t_game *game, t_bot *enemy)
{
	int	next_x;
	int	next_y;

	next_x = enemy->x;
	next_y = enemy->y;
	if (rand() % 100 < 10)
		enemy_change_direction(enemy);
	predict_step(enemy, &next_x, &next_y);
	if (game->map.map[next_x][next_y] != '1' && game->map.map[next_x][next_y]
		!= 'c' && game->map.map[next_x][next_y] != 'e')
	{
		if (!check_for_enemy(game, &next_x, &next_y))
			enemy_move(game, enemy, &next_x, &next_y);
		else
			enemy_change_direction(enemy);
	}
	else
		enemy_change_direction(enemy);
}

void	enemy_animate(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.enemies_count)
		enemy_logic(game, &game->enemies[i++]);
}

int	calculate_enemies(int width, int height)
{
	int	perimeter;
	int	enemies;

	perimeter = 2 * (width + height);
	enemies = perimeter / 20;
	if (enemies > 0)
		return (enemies);
	return (1);
}

void	enemies_spawn(t_game *game, int k, int j, int *i)
{
	if (*i >= calculate_enemies(game->map.width, game->map.height))
		return ;
	mlx_put_image_to_window(game->mlx, game->window,
		game->textures.enemy, k * 32, j * 32);
	game->enemies[(*i)].x = j;
	game->enemies[(*i)].y = k;
	game->enemies[(*i)].orient = 'U';
	game->map.enemies_count++;
	(*i)++;
}

void	enemies_init(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = game->map.height - 2;
	y = game->map.width - 2;
	i = 0;
	game->enemies = (t_bot *)malloc(
			(calculate_enemies(game->map.width, game->map.height))
			* sizeof(t_bot));
	if (!game->enemies)
		return (print_error(9), ft_on_exit(game));
	while (x > 0)
	{
		while (y > 0)
		{
			if (game->map.map[x][y] == 'o')
				enemies_spawn(game, y, x, &i);
			y--;
		}
		x--;
	}
}
