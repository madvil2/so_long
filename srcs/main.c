/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:00:08 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/10 21:55:51 by kokaimov         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		game.map = parse_map(av[1]);
		game.mlx = mlx_init();
		game.window = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Excuse me why the fuck you lookin'? What's your problem?");
		mlx_key_hook(game.window, esc_hook, &game);
		mlx_hook(game.window, 17, 0, ft_on_exit, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
