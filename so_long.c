/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:21:08 by spurple           #+#    #+#             */
/*   Updated: 2021/12/05 01:00:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update(t_game *game)
{
	render(game);
	return (1);
}

int	ft_exit(void)
{
	exit(0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	if (argc == 1)
	{
		write(1, "Error: not map\n", 15);
		return (0);
	}
	map_read(&map, &game, argv[1]);
	if (map_check(&game, 0, 0) == -1 || valid_map(&game, 0, 0) == -1)
	{
		write(1, "Error: no valid map\n", 20);
		return (0);
	}
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map.pos_y, map.pos_x, "So Long!");
	img_fill(&game);
	mlx_hook(game.win, 17, 0, ft_exit, &game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
}
