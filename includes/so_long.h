/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:48:47 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/09 21:32:31 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdarg.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <mlx.h>

// to delete after
# include <time.h>
# include <stdio.h>
//

typedef struct s_textures
{
	void	*walls;
	void	*collectibles1;
	void	*collectibles2;
	void	*exit;
	void	*right;
	void	*left;
	void	*floor;
	void	*btn;
	void	*enemy;
}	t_textures;

typedef struct s_player {
	int		x;
	int		y;
	char	orient;
	int		score;
	int		animation;
}	t_player;

typedef struct s_pos {
	int	x;
	int	y;
	int	taken;
}	t_pos;

typedef struct s_bot {
	int		x;
	int		y;
	char	orient;
}	t_bot;

typedef struct s_map {
	char	**map;
	int		height;
	int		width;
	int		coins;
	int		enemies_count;
	t_pos	*pos;
	int		exit;
}	t_map;

typedef struct s_game {
	void		*mlx;
	void		*window;
	int			pressed;
	t_map		map;
	t_player	player;
	t_textures	textures;
	t_bot		*enemies;
}	t_game;

// main.c
void	ft_on_exit(t_game *game);

// utils.c
int		init_textures(t_game *game);
void	init(t_game *game);
void	free_map(char **map);
void	print_error(int type);
void	print_moves(int *moves, t_game *game);

// hooks.c
int		mouse_hook(int mousecode, int x, int y, t_game *game);
int		key_hook(int keycode, t_game *game);

// parse.c
char	**parse_map(char *file);
int		validate_contents(int *flags, t_game *game, int i, int j);
int		validate_input(char *file, t_game *game);

// validate.c
int		validate_map(t_game *game);

// game.c
void	animation(t_game *game);
void	put_texture(int x, int y, t_game *game, char type);
void	render_map(t_game *game);


// flood_fill.c
void	flood_fill(int x, int y, t_game *game, int *has_exit);
int		flood_fill_check(t_game *game, int *has_exit);

// player.c
void	take_coin(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

// enemies_move.c
void	change_enemy_direction(t_bot *enemy);
int		kill(t_game *game, t_bot *enemy);
void	move_enemy(t_game *game, t_bot *enemy);
void	animate_enemies(t_game *game);

// enemies_spawn.c
int	calculate_enemies(int width, int height);
void	spawn_enemy(t_game *game, int x, int y);

#endif