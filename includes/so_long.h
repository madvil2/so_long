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
#define WIDTH 512
#define HEIGHT 512
# include <stdarg.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <mlx.h>

// to delete after
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
//

typedef struct	s_textures
{
	void	*walls;
	void	*collectibles1;
	void	*collectibles2;
	void	*exit;
	void	*right;
	void	*left;
	void	*floor;
}	t_textures;

typedef struct	s_player {
	int	x;
	int	y;
	char	orient;
	int	score;
}	t_player;

typedef struct	s_game {
	void	*mlx;
	void	*window;
	char	**map;
	int		map_height;
	int		map_width;
	int		coins;
	int		exit;
	t_player	player;
	t_textures	textures;
}	t_game;

// main.c

// utils.c
int		init_textures(t_game *game);
void	init(t_game *game);
void	free_map(char **map);
void	print_error(int type);

// hooks.c
int		ft_on_exit(t_game *game);
int		esc_hook(int keycode, t_game *game);

// parse.c
char	**parse_map(char *file);
int		is_map_rectangular(char **map);
int		is_surrounded_by_walls(char **map);
int		validate_contents(char **map, int *has_exit, int *has_start, int *has_coins, t_game *game);
char	**validate_input(char *file, t_game *game);


// validate.c
int	validate_map(char **map, t_game *game);

// game.c
void	render_map(t_game *game);

#endif