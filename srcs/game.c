/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:03:52 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/18 17:03:28 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_over_screen(t_game *game)
{
	char	*over_str;

	ft_printf("Game over!\n");
	over_str = ft_strdup("Game over!");
	if (!over_str)
		return (game->map.exit = 1, print_error(9));
	mlx_string_put(game->mlx, game->window, 32 * ((game->map.width - 1) / 2),
		20, 0x00FFFFFF, over_str);
	free(over_str);
}

void	animation(t_game *game)
{
	int	i;

	i = 0;
	game->player.animation = !game->player.animation;
	while (i < game->map.coins)
	{
		if (game->map.coins_pos[i].taken == 0)
			put_texture(game->map.coins_pos[i].y,
				game->map.coins_pos[i].x, game, 'c');
		i++;
	}
	enemy_animate(game);
}

void	put_texture(int x, int y, t_game *game, char type)
{
	if (type == 'o')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.floor, 32 * x, 32 * y);
	if (type == 'c')
	{
		if (game->player.animation == 1)
			mlx_put_image_to_window(game->mlx, game->window,
				game->textures.collectibles2, 32 * x, 32 * y);
		else
			mlx_put_image_to_window(game->mlx, game->window,
				game->textures.collectibles1, 32 * x, 32 * y);
	}
	if (type == 'e')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.exit, 32 * x, 32 * y);
	if (type == 'p' && game->player.orient == 'L')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.left, 32 * x, 32 * y);
	if (type == 'p' && game->player.orient == 'R')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.right, 32 * x, 32 * y);
	if (type == 'z')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.enemy, 32 * x, 32 * y);
}

void	render_map(t_game *game, int x, int y)
{
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.map[y][x] == '1')
			{
				if (x == game->map.width - 4 && y == game->map.height - 1)
					mlx_put_image_to_window(game->mlx, game->window,
						game->textures.btn, 32 * x++, 32 * y);
				else
					mlx_put_image_to_window(game->mlx, game->window,
						game->textures.walls, 32 * x, 32 * y);
			}
			else
			{
				put_texture(x, y, game, 'o');
				if (game->map.map[y][x] != '0' && game->map.map[y][x] != 'o')
					put_texture(x, y, game, game->map.map[y][x]);
			}
		}
	}
	mlx_string_put(game->mlx, game->window, 0,
		31 * game->map.height, 0X00FFFFFF, "Numbers of moves: 0");
}
