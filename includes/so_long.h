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
# include "../libft/libft.h"
# include <stdio.h> // udalit
# include <mlx.h>

typedef struct	s_player {
	int	x;
	int	y;
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
}	t_game;

// main.c

// utils.c

#endif