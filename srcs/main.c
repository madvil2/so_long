/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:00:08 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/16 00:15:05 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		t_game	game;

		init(&game);
		game.map = validate_input(av[1], &game);
		if (!game.map)
			return (0);
		game.mlx = mlx_init();
		if (game.mlx)
			game.window = mlx_new_window(game.mlx, 32 * game.map_width, 32 * game.map_height, "Excuse me why the fuck you lookin'? What's your problem?");
		if (!game.mlx || !game.window || !init_textures(&game))
			return (0);
		render_map(&game);
		mlx_key_hook(game.window, key_hook, &game);
		mlx_hook(game.window, 17, 1L << 2, ft_on_exit, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
