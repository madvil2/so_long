/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:00:08 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/16 20:01:48 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_on_exit(t_game *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
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
		if (!game.mlx || !game.window || !init_textures(&game))
			return (0);
		render_map(&game);
		mlx_mouse_hook(game.window, mouse_hook, &game);
		mlx_key_hook(game.window, key_hook, &game);
		mlx_hook(game.window, 17, 1L << 2, ft_on_exit, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
