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
	if (mousecode == 1 && (x >= (game->map.width - 4) * 32
			&& x <= (game->map.width - 2) * 32) && (y >= (game->map.height - 1)
			* 32 && y <= (game->map.height) * 32) && !game->pressed)
	{
		enemies_init(game);
		game->pressed = 1;
		mlx_put_image_to_window(game->mlx, game->window, game->textures.walls,
			32 * (game->map.width - 4), 32 * (game->map.height - 1));
		mlx_put_image_to_window(game->mlx, game->window, game->textures.walls,
			32 * (game->map.width - 3), 32 * (game->map.height - 1));
	}
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	static int	moves;

	if (keycode == 65307 || (keycode && game->map.exit == 1))
		ft_on_exit(game);
	if (keycode == 119)
		move_up(game);
	if (keycode == 97)
		move_left(game);
	if (keycode == 115)
		move_down(game);
	if (keycode == 100)
		move_right(game);
	print_moves(&moves, game);
	animation(game);
	return (0);
}
