/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:53:46 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/19 01:02:32 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	change_enemy_direction(t_bot *enemy)
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
	else {
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

int		kill(t_game *game, t_bot *enemy)
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

void	move_enemy(t_game *game, t_bot *enemy) {
	int next_x = enemy->x;
	int next_y = enemy->y;
	int occupied = 0;
	int i = 0;

	if (rand() % 100 < 10)
		change_enemy_direction(enemy);
	if (enemy->orient == 'U') next_y--;
	else if (enemy->orient == 'D') next_y++;
	else if (enemy->orient == 'L') next_x--;
	else if (enemy->orient == 'R') next_x++;

	if (game->map.map[next_x][next_y] != '1' && game->map.map[next_x][next_y] != 'c' && game->map.map[next_x][next_y] != 'e') {
		while (i < game->map.enemies_count) {
			if (game->enemies[i].x == next_x && game->enemies[i].y == next_y) {
				occupied = 1;
				break;
			}
			i++;
		}
		if (!occupied) {
			if (game->map.map[enemy->x][enemy->y] == 'o') put_texture(enemy->y, enemy->x, game, 'o');
			enemy->x = next_x;
			enemy->y = next_y;
			put_texture(enemy->y, enemy->x, game, 'z');
			if (kill(game, enemy)) {
				ft_on_exit(game);
				return ;
			}
		} else {
			change_enemy_direction(enemy);
		}
	} else {
		change_enemy_direction(enemy);
	}
}

void	animate_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.enemies_count)
	{
		move_enemy(game, &game->enemies[i]);
		i++;
	}
}
