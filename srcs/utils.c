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

void	init(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->map = NULL;
	game->coins = 0;
	game->textures.walls = NULL;
	game->textures.floor = NULL;
	game->textures.down = NULL;
	game->textures.left = NULL;
	game->textures.right = NULL;
	game->textures.up = NULL;
	game->textures.collectibles = NULL;
	game->textures.exit = NULL;
	game->player.orient = 'D';
	game->player.score = 0;
	game->exit = 0;
}

void	free_map(char **map)
{
	if (map == NULL)
		return;
	int	i;

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