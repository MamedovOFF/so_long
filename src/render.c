/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:25:54 by spurple           #+#    #+#             */
/*   Updated: 2021/12/04 18:41:12 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_win(t_game *game, int x, int i)
{
	int	y;
	int	j;

	y = 0;
	j = 0;
	while (game->maps[i][j])
	{
		if (game->maps[i][j] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->sten, y, x);
		else if (game->maps[i][j] == '0')
			mlx_put_image_to_window(game->mlx, game->win, game->back, y, x);
		else if (game->maps[i][j] == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->hero, y, x);
		else if (game->maps[i][j] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->sword, y, x);
		else if (game->maps[i][j] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->finish, y, x);
		y += 54;
		j++;
	}
}

int	render(t_game *game)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (game->maps[i])
	{
		put_win(game, x, i);
		x += 54;
		i++;
	}
	return (1);
}
