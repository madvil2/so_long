/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:37:31 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/16 20:03:53 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	mouse_hook(int mousecode, int x, int y, t_game *game)
{
	if (mousecode == 1 && (x >= (game->map.width - 4) * 32 && x <= (game->map.width - 2) * 32) && (y >= (game->map.height - 1) * 32 && y <= (game->map.height) * 32) && !game->pressed)
	{
		spawn_enemy(game, 32 * (game->map.width - 2), 32 * 1);
		game->pressed = 1;
		mlx_put_image_to_window(game->mlx, game->window, game->textures.walls, 32 * (game->map.width - 4), 32 * (game->map.height - 1));
		mlx_put_image_to_window(game->mlx, game->window, game->textures.walls, 32 * (game->map.width - 3), 32 * (game->map.height - 1));
	}
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	int x_start;
	int y_start;
	static int moves;

	x_start = game->player.x;
	y_start = game->player.y;
	if (keycode == 119)
	{
		move_up(game);
		animation(game);
	}
	if (keycode == 97)
	{
		move_left(game);
		animation(game);
	}
	if (keycode == 115)
	{
		move_down(game);
		animation(game);
	}
	if (keycode == 100)
	{
		move_right(game);
		animation(game);
	}
	if (game->player.x != x_start || game->player.y != y_start)
		print_moves(&moves, game);
	if (keycode == 65307 || game->map.exit == 1)
		ft_on_exit(game);
	return (0);
}
