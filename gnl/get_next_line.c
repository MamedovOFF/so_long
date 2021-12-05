/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:34:35 by spurple           #+#    #+#             */
/*   Updated: 2021/10/26 20:02:01 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	n_chr(char *save)
{
	int	i;

	i = 0;
	if (!save)
		return (0);
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*save_str;
	t_list			list;

	list.end = 1;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	list.buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!list.buf)
		return (NULL);
	while (!n_chr(save_str) && list.end != 0)
	{
		list.end = read(fd, list.buf, BUFFER_SIZE);
		if (list.end == -1)
		{
			free(list.buf);
			return (NULL);
		}
		list.buf[list.end] = '\0';
		save_str = ft_strjoin(save_str, list.buf);
	}
	list.str = get_str(save_str);
	save_str = get_save_str(save_str);
	free(list.buf);
	return (list.str);
}
