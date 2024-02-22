/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:53:46 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:27 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_change_direction(t_bot *enemy)
{
	if (rand() % 4 == 0)
	{
		if (enemy->orient == 'U')
			enemy->orient = 'R';
		else if (enemy->orient == 'R')
			enemy->orient = 'D';
		else if (enemy->orient == 'D')
			enemy->orient = 'L';
		else if (enemy->orient == 'L')
			enemy->orient = 'U';
	}
	else
	{
		if (enemy->orient == 'U')
			enemy->orient = 'L';
		else if (enemy->orient == 'L')
			enemy->orient = 'D';
		else if (enemy->orient == 'D')
			enemy->orient = 'R';
		else if (enemy->orient == 'R')
			enemy->orient = 'U';
	}
}

int	enemy_kill(t_game *game, t_bot *enemy)
{
	int	dx;
	int	dy;
	int	check_x;
	int	check_y;

	dx = -1;
	while (dx <= 1)
	{
		dy = -1;
		while (dy <= 1)
		{
			check_x = enemy->x + dx;
			check_y = enemy->y + dy;
			if (check_x == game->player.y && check_y == game->player.x)
				return (1);
			dy++;
		}
		dx++;
	}
	return (0);
}

void	predict_step(t_bot *enemy, int *next_y, int *next_x)
{
	if (enemy->orient == 'U')
		(*next_y)--;
	else if (enemy->orient == 'D')
		(*next_y)++;
	else if (enemy->orient == 'L')
		(*next_x)--;
	else if (enemy->orient == 'R')
		(*next_x)++;
}

int	check_for_enemy(t_game *game, int *next_x, int *next_y)
{
	int	i;

	i = 0;
	while (i < game->map.enemies_count)
	{
		if (game->enemies[i].x == *next_x && game->enemies[i].y == *next_y)
			return (1);
		i++;
	}
	return (0);
}

void	enemy_move(t_game *game, t_bot *enemy, int *next_x, int *next_y)
{
	if (game->map.map[enemy->x][enemy->y] == 'o')
		put_texture(enemy->y, enemy->x, game, 'o');
	enemy->x = *next_x;
	enemy->y = *next_y;
	put_texture(enemy->y, enemy->x, game, 'z');
	if (enemy_kill(game, enemy))
		return (game->map.exit = 1, game_over_screen(game));
}
