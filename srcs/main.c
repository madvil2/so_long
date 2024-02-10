/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:00:08 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/10 22:57:46 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_on_exit(t_game *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	exit(0);
}

int	esc_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_on_exit(game);
	return (0);
}

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

void	init(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->map = NULL;
	game->textures.w = NULL;
	game->textures.f = NULL;
	game->textures.d = NULL;
	game->textures.l = NULL;
	game->textures.r = NULL;
	game->textures.u = NULL;
	game->textures.c = NULL;
	game->textures.e = NULL;
	game->player.orient = 'D';
	game->player.score = 0;
	game->exit = 0;
}

int is_map_rectangular(char **map) {
	size_t	first_line_row;
	size_t	i;

	first_line_row = ft_strlen(map[0]);
	i = 1;
	while (map[i])
		if (ft_strlen(map[i]) != first_line_row)
			return (0);
	return (1);
}

int is_surrounded_by_walls(char **map) {
	size_t	length;
	size_t	i;

	length = ft_strlen(map[0]);
	i = 0;
	while (i < length)
		if (map[0][i++] != '1' || map[0][length - 1] != '1')
			return (0);
	i = 0;
	while (map[i] != NULL)
}

int validate_contents(char **map, int *has_exit, int *has_collectible, int *has_start) {
	// Iterate through the map to count exits, collectibles, and the starting position
	// Also, you can check for invalid characters here
}

void free_map(char **map) {
	if (map == NULL)
		return;
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}

char **validate_map(char *file)
{
	char **map;
	int has_exit;
	int has_collectible;
	int has_start;

	map = parse_map(file);
	if (!map)
		return (NULL);
	if (!is_map_rectangular(map) || !is_surrounded_by_walls(map)
		|| !validate_contents(map, &has_exit, &has_collectible, &has_start)
		|| has_exit != 1 || has_collectible < 1 || has_start != 1)
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		t_game	game;

		init(&game);
		game.map = validate_map(av[1]);
		game.mlx = mlx_init();
		game.window = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Excuse me why the fuck you lookin'? What's your problem?");
		mlx_key_hook(game.window, esc_hook, &game);
		mlx_hook(game.window, 17, 0, ft_on_exit, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
