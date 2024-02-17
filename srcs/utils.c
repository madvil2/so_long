/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:00:02 by kokaimov          #+#    #+#             */
/*   Updated: 2023/12/17 21:00:02 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_textures(t_game *game)
{
	int	a;
	char path[128]; // Ensure this is large enough to hold the full path

	a = 32;
//	game->textures.walls = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &a, &a);
//	game->textures.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &a, &a);
//	game->textures.right = mlx_xpm_file_to_image(game->mlx, "textures/p_right.xpm", &a, &a);
//	game->textures.left = mlx_xpm_file_to_image(game->mlx, "textures/p_left.xpm", &a, &a);
//	game->textures.collectibles1 = mlx_xpm_file_to_image(game->mlx, "textures/exp1.xpm", &a, &a);
//	game->textures.collectibles2 = mlx_xpm_file_to_image(game->mlx, "textures/exp2.xpm", &a, &a);
//	game->textures.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &a, &a);
	sprintf(path, "%swall.xpm", TEXTURES_PATH);
	game->textures.walls = mlx_xpm_file_to_image(game->mlx, path, &a, &a);

	sprintf(path, "%sfloor.xpm", TEXTURES_PATH);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx, path, &a, &a);

	sprintf(path, "%sp_right.xpm", TEXTURES_PATH);
	game->textures.right = mlx_xpm_file_to_image(game->mlx, path, &a, &a);

	sprintf(path, "%sp_left.xpm", TEXTURES_PATH);
	game->textures.left = mlx_xpm_file_to_image(game->mlx, path, &a, &a);

	sprintf(path, "%sexp1.xpm", TEXTURES_PATH);
	game->textures.collectibles1 = mlx_xpm_file_to_image(game->mlx, path, &a, &a);

	sprintf(path, "%sexp2.xpm", TEXTURES_PATH);
	game->textures.collectibles2 = mlx_xpm_file_to_image(game->mlx, path, &a, &a);

	sprintf(path, "%sexit.xpm", TEXTURES_PATH);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, path, &a, &a);
	if (!game->textures.walls || !game->textures.floor || !game->textures.right || !game->textures.left || !game->textures.collectibles1 || !game->textures.collectibles2 || !game->textures.exit)
		return (0);
	return (1);
}

void	init(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->map.map = NULL;
	game->map.coins = 0;
	game->textures.walls = NULL;
	game->textures.floor = NULL;
	game->textures.left = NULL;
	game->textures.right = NULL;
	game->textures.collectibles1 = NULL;
	game->textures.collectibles2 = NULL;
	game->textures.exit = NULL;
	game->player.orient = 'R';
	game->player.score = 0;
	game->map.exit = 0;
}

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
	map = NULL;
}

void	print_error(int type)
{
	ft_printf("Error\n");
	if (type == 1)
		ft_printf("The map must be rectangular.\n");
	else if (type == 2)
		ft_printf("The map must be closed/surrounded by walls.\n");
	else if (type == 3)
		ft_printf("The map must contain only valid characters.\n");
	else if (type == 4)
		ft_printf("The map must contain exactly one exit.\n");
	else if (type == 5)
		ft_printf("The map must contain at least 1 collectible.\n");
	else if (type == 6)
		ft_printf("The map must contain exactly one start.\n");
	else if (type == 7)
		ft_printf("The map must have \".ber\" extension.\n");
	else if (type == 8)
		ft_printf("The map must have a valid path in it.\n");
}

void	print_moves(int *moves, t_game *game)
{
	char	*mv_str;

	ft_printf("Number of moves: %i\n", ++(*moves));
	mv_str = ft_itoa(*moves);
	if (!mv_str)
	{
		game->map.exit = 1;
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->textures.walls,
		32 * 3, 32 * (game->map.height - 1));
	mlx_string_put(game->mlx, game->window, 110,
		31 * game->map.height, 0x00FFFFFF, mv_str);
	free(mv_str);
}
