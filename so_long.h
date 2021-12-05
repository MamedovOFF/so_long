/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:24:58 by spurple           #+#    #+#             */
/*   Updated: 2021/12/05 01:07:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "gnl/get_next_line.h"

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*hero;
	void	*var;
	void	*sword;
	void	*sten;
	void	*back;
	void	*finish;
	int		plr_y;
	int		plr_x;
	int		img_width;
	int		img_height;
	int		step;
	char	**maps;
	int		point;
}	t_game;
typedef struct m_data {
	char	**maps;
	int		pos_x;
	int		pos_y;
	int		i_map;
	int		j_map;
}	t_map;
void		img_fill(t_game *game);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		move(int x, int y, t_game *game);
void		map_read_str(t_map *map, t_game *game, int l, char *s);
void		malloc_arr(t_map *map, char *argv);
void		put_win(t_game *game, int x, int i);
char		*ft_itoa(int n);
char		*ft_strdup(const char *str);
int			move_check(t_game *game, int x, int y);
int			key_hook(int keycode, t_game *game);
int			check_symbil(t_game *game);
int			valid_map(t_game *game, int i, int j);
int			map_check(t_game *game, int i, int j);
int			map_read(t_map *map, t_game *game, char *argv);
int			render(t_game *game);
int			update(t_game *game);
int			ft_exit(void);
int			animation(t_game *game);
#endif
