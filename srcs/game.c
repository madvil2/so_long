/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:03:52 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/15 19:07:58 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_texture(int x, int y, t_game *game, char type)
{
	if (type == 'o')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.floor, 32 * x, 32 * y);
	if (type == 'c')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.collectibles1, 32 * x, 32 * y);
	if (type == 'e')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.exit, 32 * x, 32 * y);
	if (type == 'p' && game->player.orient == 'L')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.left, 32 * x, 32 * y);
	if (type == 'p' && game->player.orient == 'R')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.right, 32 * x, 32 * y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->textures.walls, 32 * x, 32 * y);
			else
			{
				put_texture(x, y, game, 'o');
				if (game->map[y][x] != '0' && game->map[y][x] != 'o')
					put_texture(x, y, game, game->map[y][x]);
			}
		}
	}
	mlx_string_put(game->mlx, game->window, 0,
		31 * game->map_height, 0X00FFFFFF, "Numbers of moves: 0");
}
