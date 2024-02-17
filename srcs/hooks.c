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

void	move_up(t_game *game)
{
	if (game->map.map[game->player.y - 1][game->player.x] == '1')
		return (put_texture(game->player.x, game->player.y, game, 'p'));
	if (game->map.map[game->player.y][game->player.x] != 'e')
		game->map.map[game->player.y][game->player.x] = 'o';
	put_texture(game->player.x, game->player.y, game, 'o');
	put_texture(game->player.x, game->player.y, game,
		game->map.map[game->player.y][game->player.x]);
	game->player.y--;
	if (game->map.map[game->player.y][game->player.x] == 'c'
		|| game->map.map[game->player.y][game->player.x] == 'o')
	{
		if (game->map.map[game->player.y][game->player.x] == 'c')
			game->player.score++;
		put_texture(game->player.x, game->player.y, game, 'o');
	}
	put_texture(game->player.x, game->player.y, game, 'p');
	if (game->map.map[game->player.y][game->player.x] == 'e'
		&& game->player.score == game->map.coins)
	{
		game->map.exit = 1;
		return ;
	}
	if (game->map.map[game->player.y][game->player.x] != 'e')
		game->map.map[game->player.y][game->player.x] = 'p';
}

void	move_down(t_game *game)
{
	if (game->map.map[game->player.y + 1][game->player.x] == '1')
		return (put_texture(game->player.x, game->player.y, game, 'p'));
	if (game->map.map[game->player.y][game->player.x] != 'e')
		game->map.map[game->player.y][game->player.x] = 'o';
	put_texture(game->player.x, game->player.y, game, 'o');
	put_texture(game->player.x, game->player.y, game,
		game->map.map[game->player.y][game->player.x]);
	game->player.y++;
	if (game->map.map[game->player.y][game->player.x] == 'c'
		|| game->map.map[game->player.y][game->player.x] == 'o')
	{
		if (game->map.map[game->player.y][game->player.x] == 'c')
			game->player.score++;
		put_texture(game->player.x, game->player.y, game, 'o');
	}
	put_texture(game->player.x, game->player.y, game, 'p');
	if (game->map.map[game->player.y][game->player.x] == 'e'
		&& game->player.score == game->map.coins)
	{
		game->map.exit = 1;
		return ;
	}
	if (game->map.map[game->player.y][game->player.x] != 'e')
		game->map.map[game->player.y][game->player.x] = 'p';
}

void	move_left(t_game *game)
{
	game->player.orient = 'L';
	if (game->map.map[game->player.y][game->player.x - 1] == '1')
		return (put_texture(game->player.x, game->player.y, game, 'p'));
	if (game->map.map[game->player.y][game->player.x] != 'e')
		game->map.map[game->player.y][game->player.x] = 'o';
	put_texture(game->player.x, game->player.y, game, 'o');
	put_texture(game->player.x, game->player.y, game,
		game->map.map[game->player.y][game->player.x]);
	game->player.x--;
	if (game->map.map[game->player.y][game->player.x] == 'c'
		|| game->map.map[game->player.y][game->player.x] == 'o')
	{
		if (game->map.map[game->player.y][game->player.x] == 'c')
			game->player.score++;
		put_texture(game->player.x, game->player.y, game, 'o');
	}
	put_texture(game->player.x, game->player.y, game, 'p');
	if (game->map.map[game->player.y][game->player.x] == 'e'
		&& game->player.score == game->map.coins)
	{
		game->map.exit = 1;
		return ;
	}
	if (game->map.map[game->player.y][game->player.x] != 'e')
		game->map.map[game->player.y][game->player.x] = 'p';
}

void	move_right(t_game *game)
{
	game->player.orient = 'R';
	if (game->map.map[game->player.y][game->player.x + 1] == '1')
		return (put_texture(game->player.x, game->player.y, game, 'p'));
	if (game->map.map[game->player.y][game->player.x] != 'e')
		game->map.map[game->player.y][game->player.x] = 'o';
	put_texture(game->player.x, game->player.y, game, 'o');
	put_texture(game->player.x, game->player.y, game,
		game->map.map[game->player.y][game->player.x]);
	game->player.x++;
	if (game->map.map[game->player.y][game->player.x] == 'c'
		|| game->map.map[game->player.y][game->player.x] == 'o')
	{
		if (game->map.map[game->player.y][game->player.x] == 'c')
			game->player.score++;
		put_texture(game->player.x, game->player.y, game, 'o');
	}
	put_texture(game->player.x, game->player.y, game, 'p');
	if (game->map.map[game->player.y][game->player.x] == 'e'
		&& game->player.score == game->map.coins)
	{
		game->map.exit = 1;
		return ;
	}
	if (game->map.map[game->player.y][game->player.x] != 'e')
		game->map.map[game->player.y][game->player.x] = 'p';
}

int	key_hook(int keycode, t_game *game)
{
	int			x_start;
	int			y_start;
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
	if (keycode == 65307 || game->map.exit == 1)
		ft_on_exit(game);
	return (0);
}
