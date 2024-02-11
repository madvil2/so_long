/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:17:41 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/11 19:17:41 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_map(char **map)
{
	int		has_exit;
	int		has_collectible;
	int		has_start;

	has_exit = 0;
	has_collectible = 0;
	has_start = 0;
	if (!is_map_rectangular(map) || !is_surrounded_by_walls(map)
		|| !validate_contents(map, &has_exit, &has_collectible, &has_start)
		|| has_exit != 1 || has_collectible < 1 || has_start != 1)
	{
		if (has_exit != 1)
			print_error(4);
		if (has_collectible < 1)
			print_error(5);
		if (has_start != 1)
			print_error(6);
		free_map(map); // suda ne dohodit!
		return (0);
	}
	return (1);
}