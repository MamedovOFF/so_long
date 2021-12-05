/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:25:29 by spurple           #+#    #+#             */
/*   Updated: 2021/12/04 18:32:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_fill(t_game *game)
{
	game->back = mlx_xpm_file_to_image(game->mlx, "./image/background4.xpm", \
	&game->img_width, &game->img_height);
	game->sten = mlx_xpm_file_to_image(game->mlx, "./image/stena.xpm", \
	&game->img_width, &game->img_height);
	game->var = mlx_xpm_file_to_image(game->mlx, "./image/var.xpm", \
	&game->img_width, &game->img_height);
	game->hero = mlx_xpm_file_to_image(game->mlx, "./image/hero1.xpm", \
	&game->img_width, &game->img_height);
	game->sword = mlx_xpm_file_to_image(game->mlx, "./image/File.xpm", \
	&game->img_width, &game->img_height);
	game->finish = mlx_xpm_file_to_image(game->mlx, "./image/finish.xpm", \
	&game->img_width, &game->img_height);
}
