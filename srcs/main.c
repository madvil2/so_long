/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:00:08 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/09 21:08:27 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_on_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	esc_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_on_exit(game);
	return (0);
}

int	main(void)
{
	t_game	game;
	game.mlx = mlx_init();
	game.mlx = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Excuse me why the fuck you lookin'? What's your problem?");
	mlx_key_hook(game.window, esc_hook, &game);
	mlx_hook(game.window, 17, 0, ft_on_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
