/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:00:08 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/21 23:44:44 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_enemies(t_game *game)
{
	if (game->enemies)
	{
		free(game->enemies);
		game->enemies = NULL;
	}
}

void	free_coins_pos(t_game *game)
{
	if (game->map.coins_pos)
	{
		free(game->map.coins_pos);
		game->map.coins_pos = NULL;
	}
}

void	free_mlx(t_game *game)
{
	if (game->textures.enemy)
		mlx_destroy_image(game->mlx, game->textures.enemy);
	if (game->textures.btn)
		mlx_destroy_image(game->mlx, game->textures.btn);
	if (game->textures.collectibles1)
		mlx_destroy_image(game->mlx, game->textures.collectibles1);
	if (game->textures.collectibles2)
		mlx_destroy_image(game->mlx, game->textures.collectibles2);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	if (game->textures.left)
		mlx_destroy_image(game->mlx, game->textures.left);
	if (game->textures.right)
		mlx_destroy_image(game->mlx, game->textures.right);
	if (game->textures.walls)
		mlx_destroy_image(game->mlx, game->textures.walls);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
}

void	ft_on_exit(t_game *game)
{
	free_mlx(game);
	free_enemies(game);
	free_coins_pos(game);
	free_map(game->map.map);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		srand(time(NULL));
		init(&game);
		if (!validate_input(av[1], &game))
			return (0);
		game.mlx = mlx_init();
		if (game.mlx)
			game.window = mlx_new_window(game.mlx, 32 * game.map.width,
					32 * game.map.height, "so_long");
		if (!game.mlx || !game.window || !init_textures(&game, 32))
			return (0);
		render_map(&game, -1, -1);
		mlx_mouse_hook(game.window, mouse_hook, &game);
		mlx_key_hook(game.window, key_hook, &game);
		mlx_hook(game.window, 17, 1L << 2, (int (*)())ft_on_exit, &game);
		mlx_loop(game.mlx);
	}
	return (print_error(11), 0);
}
