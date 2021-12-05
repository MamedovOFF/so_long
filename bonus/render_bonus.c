/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:27:53 by spurple           #+#    #+#             */
/*   Updated: 2021/12/04 18:43:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render_map(t_game *game, int i, int x)
{
	int	y;
	int	j;

	y = 0;
	j = 0;
	while (game->maps[i][j])
	{
		if (game->maps[i][j] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->sten, y, x);
		else if (game->maps[i][j] == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->hero, y, x);
		else if (game->maps[i][j] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->sword, y, \
										x);
		else if (game->maps[i][j] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->finish, \
										y, x);
		else if (game->maps[i][j] == 'V')
			mlx_put_image_to_window(game->mlx, game->win, game->var, y, x);
		else if (game->maps[i][j] == '0')
			mlx_put_image_to_window(game->mlx, game->win, game->back, y, x);
		y += 54;
		j++;
	}
	return (1);
}

int	render(t_game *game)
{
	int		x;
	int		i;
	char	*step;

	x = 30;
	i = 0;
	step = ft_itoa(game->step);
	mlx_clear_window(game->mlx, game->win);
	while (game->maps[i])
	{
		mlx_string_put(game->mlx, game->win, 5, 5, 0x00FF0000, step);
		render_map(game, i, x);
		x += 54;
		i++;
	}
	free(step);
	return (1);
}
