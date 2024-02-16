/* ************************************************************************** */
/*                                                                            */
/*                dd                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:37:31 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/11 14:37:31 by kokaimov         ###   ########.fr       */
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

void	move_up(t_game *game)
{
	if (game->map[game->player.y - 1][game->player.x] == '1')
		return (put_texture(game->player.x, game->player.y, game, 'p'));
	if (game->map[game->player.y][game->player.x] != 'e')
		game->map[game->player.y][game->player.x] = 'o';
	put_texture(game->player.x, game->player.y, game, 'o');
	put_texture(game->player.x, game->player.y, game, game->map[game->player.y][game->player.x]);
	game->player.y--;
	game->coin_anim_toggle = !game->coin_anim_toggle;
	if (game->map[game->player.y][game->player.x] == 'c' || game->map[game->player.y][game->player.x] == 'o')
	{
		if (game->map[game->player.y][game->player.x] == 'c')
			game->player.score++;
		put_texture(game->player.x, game->player.y, game, 'o');
	}
	put_texture(game->player.x, game->player.y, game, 'p');
	if (game->map[game->player.y][game->player.x] == 'e' && game->player.score == game->coins)
	{
		game->exit = 1;
		return ;
	}
	if (game->map[game->player.y][game->player.x] != 'e')
		game->map[game->player.y][game->player.x] = 'p';
}

void	move_down(t_game *game)
{
	if (game->map[game->player.y + 1][game->player.x] == '1')
		return (put_texture(game->player.x, game->player.y, game, 'p'));
	if (game->map[game->player.y][game->player.x] != 'e')
		game->map[game->player.y][game->player.x] = 'o';
	put_texture(game->player.x, game->player.y, game, 'o');
	put_texture(game->player.x, game->player.y, game, game->map[game->player.y][game->player.x]);
	game->player.y++;
	game->coin_anim_toggle = !game->coin_anim_toggle;
	if (game->map[game->player.y][game->player.x] == 'c' || game->map[game->player.y][game->player.x] == 'o')
	{
		if (game->map[game->player.y][game->player.x] == 'c')
			game->player.score++;
		put_texture(game->player.x, game->player.y, game, 'o');
	}
	put_texture(game->player.x, game->player.y, game, 'p');
	if (game->map[game->player.y][game->player.x] == 'e' && game->player.score == game->coins)
	{
		game->exit = 1;
		return ;
	}
	if (game->map[game->player.y][game->player.x] != 'e')
		game->map[game->player.y][game->player.x] = 'p';
}

void	move_left(t_game *game)
{
	game->player.orient = 'L';
	if (game->map[game->player.y][game->player.x - 1] == '1')
		return (put_texture(game->player.x, game->player.y, game, 'p'));
	if (game->map[game->player.y][game->player.x] != 'e')
		game->map[game->player.y][game->player.x] = 'o';
	put_texture(game->player.x, game->player.y, game, 'o');
	put_texture(game->player.x, game->player.y, game, game->map[game->player.y][game->player.x]);
	game->player.x--;
	game->coin_anim_toggle = !game->coin_anim_toggle;
	if (game->map[game->player.y][game->player.x] == 'c' || game->map[game->player.y][game->player.x] == 'o')
	{
		if (game->map[game->player.y][game->player.x] == 'c')
			game->player.score++;
		put_texture(game->player.x, game->player.y, game, 'o');
	}
	put_texture(game->player.x, game->player.y, game, 'p');
	if (game->map[game->player.y][game->player.x] == 'e' && game->player.score == game->coins)
	{
		game->exit = 1;
		return ;
	}
	if (game->map[game->player.y][game->player.x] != 'e')
		game->map[game->player.y][game->player.x] = 'p';
}

void	move_right(t_game *game)
{
	game->player.orient = 'R';
	if (game->map[game->player.y][game->player.x + 1] == '1')
		return (put_texture(game->player.x, game->player.y, game, 'p'));
	if (game->map[game->player.y][game->player.x] != 'e')
		game->map[game->player.y][game->player.x] = 'o';
	put_texture(game->player.x, game->player.y, game, 'o');
	put_texture(game->player.x, game->player.y, game, game->map[game->player.y][game->player.x]);
	game->player.x++;
	game->coin_anim_toggle = !game->coin_anim_toggle;
	if (game->map[game->player.y][game->player.x] == 'c' || game->map[game->player.y][game->player.x] == 'o')
	{
		if (game->map[game->player.y][game->player.x] == 'c')
			game->player.score++;
		put_texture(game->player.x, game->player.y, game, 'o');
	}
	put_texture(game->player.x, game->player.y, game, 'p');
	if (game->map[game->player.y][game->player.x] == 'e' && game->player.score == game->coins)
	{
		game->exit = 1;
		return ;
	}
	if (game->map[game->player.y][game->player.x] != 'e')
		game->map[game->player.y][game->player.x] = 'p';
}

void	print_moves(int *moves, t_game *game)
{
	char	*mv_str;

	ft_printf("Number of moves: %i\n", ++(*moves));
	ft_printf("coin_anim_toggle: %i\n", game->coin_anim_toggle);
	mv_str = ft_itoa(*moves);
	if (!mv_str)
	{
		game->exit = 1;
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->textures.walls, 32 * 3, 32 * (game->map_height - 1));
	mlx_string_put(game->mlx, game->window, 110, 31 * game->map_height, 0x00FFFFFF, mv_str);
	free(mv_str);
}

int	key_hook(int keycode, t_game *game)
{
	int	x_start;
	int	y_start;

	static int	moves;
	x_start = game->player.x;
	y_start = game->player.y;
	if (keycode == 119)
		move_up(game);
	if (keycode == 97)
		move_left(game);
	if (keycode == 115)
		move_down(game);
	if (keycode == 100)
		move_right(game);
	if (game->player.x != x_start || game->player.y != y_start)
		print_moves(&moves, game);
	if (keycode == 65307 || game->exit == 1)
		ft_on_exit(game);
	return (0);
}