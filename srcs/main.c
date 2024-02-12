/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:00:08 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/10 22:57:46 by kokaimov         ###   ########.fr       */
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
		game.window = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Excuse me why the fuck you lookin'? What's your problem?");
		mlx_key_hook(game.window, esc_hook, &game);
		mlx_hook(game.window, 17, 0, ft_on_exit, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
