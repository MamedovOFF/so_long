/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:30:40 by spurple           #+#    #+#             */
/*   Updated: 2021/12/05 00:46:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_symbil(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->maps[i])
	{
		j = 0;
		while (game->maps[i][j])
		{
			if (game->maps[i][j] != 'P' && game->maps[i][j] != 'E' &&
			game->maps[i][j] != 'C' && game->maps[i][j] != '0' && \
			game->maps[i][j] != '1' && game->maps[i][j] != '\n' && \
			game->maps[i][j] != '\0')
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	if (ft_strlen(game->maps[i - 2]) != ft_strlen(game->maps[i - 1]) + 1)
		return (-1);
	return (1);
}

int	valid_map(t_game *game, int i, int j)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	while (game->maps[i])
	{
		j = 0;
		while (game->maps[i][j])
		{
			if (game->maps[i][j] == 'P')
				p++;
			else if (game->maps[i][j] == 'E')
				e++;
			else if (game->maps[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c < 1 || p < 1 || e < 1)
		return (-1);
	return (i);
}

int	map_check(t_game *game, int i, int j)
{
	while (game->maps[i])
	{
		while (game->maps[i][j])
		{
			if (i == 0)
				if (game->maps[0][j] != '1' && game->maps[0][j] != '\n')
					return (-1);
			j++;
		}
		if (game->maps[i][j - 2] != '1' || game->maps[i][0] != '1')
			return (-1);
		j = 0;
		if (game->maps[i + 1] && i != 0)
			if (ft_strlen(game->maps[i]) != ft_strlen(game->maps[i - 1]))
				return (-1);
		i++;
	}
	while (game->maps[i - 1][++j])
	{
		if (game->maps[i - 1][j] != '1')
			return (-1);
	}
	if (check_symbil(game) == -1)
		return (-1);
	return (1);
}
