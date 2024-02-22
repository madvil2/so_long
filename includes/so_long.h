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
# include <time.h>

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

typedef struct s_coins_pos {
	int	x;
	int	y;
	int	taken;
}	t_coins_pos;

typedef struct s_bot {
	int		x;
	int		y;
	char	orient;
}	t_bot;

typedef struct s_map {
	char		**map;
	int			height;
	int			width;
	int			coins;
	int			enemies_count;
	t_coins_pos	*coins_pos;
	int			exit;
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
void	free_enemies(t_game *game);
void	free_coins_pos(t_game *game);
void	free_mlx(t_game *game);
void	ft_on_exit(t_game *game);

// utils.c
int		init_textures(t_game *game, int a);
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
void	game_over_screen(t_game *game);
void	animation(t_game *game);
void	put_texture(int x, int y, t_game *game, char type);
void	render_map(t_game *game, int x, int y);

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
void	enemy_change_direction(t_bot *enemy);
int		enemy_kill(t_game *game, t_bot *enemy);
void	predict_step(t_bot *enemy, int *next_y, int *next_x);
int		check_for_enemy(t_game *game, int *next_x, int *next_y);
void	enemy_move(t_game *game, t_bot *enemy, int *next_x, int *next_y);

// enemies_logic.c
void	enemy_logic(t_game *game, t_bot *enemy);
void	enemy_animate(t_game *game);
int		calculate_enemies(int width, int height);
void	enemies_init(t_game *game);
void	game_over_screen(t_game *game);

#endif