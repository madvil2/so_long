/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:00:08 by kokaimov          #+#    #+#             */
/*   Updated: 2023/12/19 02:11:53 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	game_init(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", false);
	if (!game->mlx)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 1);
		return (EXIT_FAILURE);
	}
	game->image = mlx_new_image(game->mlx, 128, 128);
	if (!game->image)
	{
		mlx_close_window(game->mlx);
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 1);
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 1);
		return(EXIT_FAILURE);
	}
	mlx_loop_hook(game->mlx, ft_hook, game->mlx);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}

void	init_pointers(t_game *game)
{
	game->mlx = NULL;
	game->image = NULL;
}

int	main(void)
{
	t_game	game;

	game_init(&game);
	return (0);
}
