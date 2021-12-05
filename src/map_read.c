/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:27:58 by spurple           #+#    #+#             */
/*   Updated: 2021/12/05 14:37:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_read_str(t_map *map, t_game *game, int l, char *s)
{
	int		j;

	map->pos_y = 0;
	j = 0;
	while (map->maps[l][j])
	{
		map->maps[l][j] = map->maps[l][j];
		map->pos_y += 54;
		if (s[j] == 'P')
		{
			game->plr_x = l;
			game->plr_y = j;
		}
		if (s[j] == 'C')
			game->point++;
		j++;
	}
}

void	malloc_arr(t_map *map, char *argv)
{
	int		j;
	int		i;
	char	*s;

	i = open(argv, O_RDONLY);
	j = 0;
	while (1)
	{
		s = get_next_line(i);
		j++;
		free(s);
		if (!s)
			break ;
	}
	free(s);
	close(i);
	map->maps = malloc((j + 1) * sizeof(char *));
	if (!map->maps)
		exit(0);
}

int	map_read(t_map *map, t_game *game, char *argv)
{
	int		i;
	int		l;

	l = 0;
	map->pos_x = 0;
	game->point = 0;
	game->step = 0;
	malloc_arr(map, argv);
	i = open(argv, O_RDONLY);
	map->maps[l] = get_next_line(i);
	if (!map->maps[l])
	{
		write(1, "Empty file\n", 11);
		exit(1);
	}
	while (map->maps[l])
	{
		map_read_str(map, game, l, map->maps[l]);
		map->pos_x += 54;
		l++;
		map->maps[l] = get_next_line(i);
	}
	close(i);
	game->maps = map->maps;
	return (1);
}
