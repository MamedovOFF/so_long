/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:25:37 by spurple           #+#    #+#             */
/*   Updated: 2021/12/05 00:58:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = n * -1;
	}
	else
		num = n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

void	move(int x, int y, t_game *game)
{
	game->step++;
	if (game->maps[x][y] == 'C')
		game->point--;
	if (game->maps[x][y] == 'V')
		exit(0);
	if (game->maps[x][y] == 'E' && game->point == 0)
		exit(0);
	game->maps[game->plr_x][game->plr_y] = '0';
	game->maps[x][y] = 'P';
	ft_putnbr_fd(game->step, 1);
	write(1, "\n", 1);
}

int	move_check(t_game *game, int x, int y)
{
	if (game->maps[x][y] != '1' && \
	(game->maps[x][y] != 'E' || game->point == 0))
	{
		return (1);
	}
	return (-1);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 && move_check(game, game->plr_x - 1, game->plr_y) == 1)
	{
		move(game->plr_x - 1, game->plr_y, game);
		game->plr_x -= 1;
	}
	if (keycode == 1 && move_check(game, game->plr_x + 1, game->plr_y) == 1)
	{
		move(game->plr_x + 1, game->plr_y, game);
		game->plr_x += 1;
	}
	if (keycode == 0 && move_check(game, game->plr_x, game->plr_y - 1) == 1)
	{
		move(game->plr_x, game->plr_y - 1, game);
		game->plr_y -= 1;
	}
	if (keycode == 2 && move_check(game, game->plr_x, game->plr_y + 1) == 1)
	{
		move(game->plr_x, game->plr_y + 1, game);
		game->plr_y += 1;
	}
	return (1);
}
