/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:29:41 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/11 14:33:20 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**parse_map(char *file)
{
	char	**map;
	char	*line;
	int		fd;
	int		lines = 0;
	int		i = 0;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		lines++;
	}
	close(fd);
	fd = open(file, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	while ((line = get_next_line(fd)) != NULL && i < lines)
		map[i++] = line;
	map[i] = NULL;
	close(fd);
	return (map);
}

int	is_map_rectangular(char **map)
{
	size_t	first_line_row;
	size_t	i;
	size_t	len;

	first_line_row = ft_strlen(map[0]);
	i = 1;
	len = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if ((len != first_line_row && map[i + 1]) || (len != first_line_row - 1 && !map[i + 1]))
			return (print_error(1), 0);
		// Deleting '\n' at the end of each row
		map[i][first_line_row - 1] = 0;
		i++;
	}
	// Deleting '\n' on the first row
	map[0][first_line_row - 1] = 0;
	return (1);
}

int	is_surrounded_by_walls(char **map)
{
	size_t	length;
	size_t	i;
	size_t	lastRowIndex;

	length = ft_strlen(map[0]);
	i = 0;
	lastRowIndex = 0;
	while (map[lastRowIndex])
		lastRowIndex++;
	// Check first and last rows for walls
	while (i < length)
		if (map[0][i++] != '1')
			return (print_error(2), 0);
	i = 0;
	while (i < length)
		if (map[lastRowIndex - 1][i++] != '1')
			return (print_error(2), 0);
	// Check the first and last character of each row
	i = -1;
	while (map[++i] != NULL)
		if (map[i][0] != '1' || map[i][length - 1] != '1')
			return (print_error(2), 0);
	return (1);
}

int	validate_contents(char **map, int *has_exit, int *has_start, int *has_coins, t_game *game)
{
	int	i;
	int	j;

	*has_exit = 0;
	*has_start = 0;
	*has_coins = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				(*has_exit)++;
			else if (map[i][j] == 'C')
				(*has_coins)++;
			else if (map[i][j] == 'P')
			{
				game->player.y = j;
				game->player.x = i;
				(*has_start)++;
			}
			else if (!(map[i][j] == '0' || map[i][j] == '1'))
				return (print_error(3), 0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**validate_input(char *file, t_game *game)
{
	char **map;
	size_t	nameLen;

	nameLen = ft_strlen(file);
	if (nameLen < 4 || ft_strncmp(&file[nameLen - 4], ".ber", 4))
		return (print_error(7), NULL);
	map = parse_map(file);
	if (!map)
		return (NULL);
	if (validate_map(map, game))
		return (map);
	return (NULL);
}