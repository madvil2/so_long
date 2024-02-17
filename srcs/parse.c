/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:29:41 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/16 22:15:47 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	read_file(char *file)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		lines++;
	}
	close(fd);
	return (lines);
}

char	**parse_map(char *file)
{
	char	**map;
	char	*line;
	int		fd;
	int		lines;
	int		i;

	i = 0;
	lines = read_file(file);
	fd = open(file, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL && i < lines)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	validate_input(char *file, t_game *game)
{
	size_t	name_len;

	name_len = ft_strlen(file);
	if (name_len < 4 || ft_strncmp(&file[name_len - 4], ".ber", 4))
		return (print_error(7), 0);
	game->map.map = parse_map(file);
	if (!game->map.map)
		return (0);
	if (validate_map(game))
		return (1);
	return (0);
}
