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
#define BUFF_SIZE 10000
# include <stdarg.h>
# include <fcntl.h>
# include "../libft/libft.h"

// to delete after
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//

# include <mlx.h>

typedef struct	s_textures
{
	void	*w;
	void	*c;
	void	*e;
	void	*d;
	void	*u;
	void	*r;
	void	*l;
	void	*f;
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
	int		coin;
	int		exit;
	t_player	player;
	t_textures	textures;
}	t_game;

// main.c

// utils.c

#endif