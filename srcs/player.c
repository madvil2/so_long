/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:55:26 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/19 00:55:26 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	take_coin(t_game *game)
{
	int	i;

	i = 0;
	game->player.animation = !game->player.animation;
	while (i < game->map.coins)
	{
		if (game->map.pos[i].x == game->player.y && game->map.pos[i].y == game->player.x)
			game->map.pos[i].taken = 1;
		i++;
	}
}


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
		{
			take_coin(game);
			game->player.score++;
		}
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
		{
			take_coin(game);
			game->player.score++;
		}
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
		{
			take_coin(game);
			game->player.score++;
		}
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
		{
			take_coin(game);
			game->player.score++;
		}
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