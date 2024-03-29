/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:17:41 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/17 03:04:51 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_map_rectangular(char **map)
{
	size_t	first_line_row;
	size_t	i;
	size_t	len;

	if (!map[0])
		return (print_error(10), 0);
	first_line_row = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if ((len != first_line_row && map[i + 1])
			|| (len != first_line_row - 1 && !map[i + 1]))
			return (print_error(1), 0);
		map[i][first_line_row - 1] = 0;
		i++;
	}
	map[0][first_line_row - 1] = 0;
	return (1);
}

static int	is_surrounded_by_walls(char **map)
{
	size_t	length;
	size_t	i;
	size_t	last_row_index;

	length = ft_strlen(map[0]);
	i = 0;
	last_row_index = 0;
	while (map[last_row_index])
		last_row_index++;
	while (i < length)
		if (map[0][i++] != '1')
			return (print_error(2), 0);
	i = 0;
	while (i < length)
		if (map[last_row_index - 1][i++] != '1')
			return (print_error(2), 0);
	i = -1;
	while (map[++i] != NULL)
		if (map[i][0] != '1' || map[i][length - 1] != '1')
			return (print_error(2), 0);
	return (1);
}

int	validate_contents(int *flags, t_game *game, int i, int j)
{
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'E')
				(flags[0])++;
			else if (game->map.map[i][j] == 'C')
				(flags[1])++;
			else if (game->map.map[i][j] == 'P')
			{
				game->player.y = i;
				game->player.x = j;
				(flags[2])++;
			}
			else if (!(game->map.map[i][j] == '0'
				|| game->map.map[i][j] == '1'))
				return (print_error(3), 0);
			game->map.width = ++j;
		}
		game->map.height = ++i;
	}
	game->map.coins_pos = (t_coins_pos *)malloc((flags[1])
			* sizeof(t_coins_pos));
	return (1);
}

int	validate_map(t_game *game)
{
	int		flags[3];

	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	if (!is_map_rectangular(game->map.map)
		|| !is_surrounded_by_walls(game->map.map))
		return (free_map(game->map.map), 0);
	if (!validate_contents(flags, game, 0, 0)
		|| flags[0] != 1 || flags[1] < 1 || flags[2] != 1)
	{
		if (flags[0] != 1)
			print_error(4);
		if (flags[1] < 1)
			print_error(5);
		if (flags[2] != 1)
			print_error(6);
		free_map(game->map.map);
		return (0);
	}
	if (!flood_fill_check(game, &flags[0]) || game->map.coins != flags[1])
		return (print_error(8), free_map(game->map.map),
			free_coins_pos(game), 0);
	return (1);
}
