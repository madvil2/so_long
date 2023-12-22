/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:48:47 by kokaimov          #+#    #+#             */
/*   Updated: 2023/12/19 02:04:23 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#define WIDTH 512
#define HEIGHT 512
# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h> // udalit
# include "/Users/madvil2/Projects/so_long/mlx/include/MLX42/MLX42.h"

typedef struct	s_game
{
	mlx_t *mlx;
	mlx_image_t *image;
}	t_game;



// main.c

// utils.c

#endif