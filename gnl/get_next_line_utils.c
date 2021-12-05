/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:59:41 by spurple           #+#    #+#             */
/*   Updated: 2021/10/26 19:16:32 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_str(char *str)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	j = 0;
	if (!str || (str && !str[0]))
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	res = (char *)malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	while (j < i + 1)
	{
		res[j] = str[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*get_save_str(char *save)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
	if (!str)
		return (NULL);
	i++;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *destination, const void *src, size_t n)
{
	char		*dest;
	const char	*source;
	size_t		i;

	i = -1;
	dest = (char *)destination;
	source = (char *)src;
	if (dest || source)
	{
		if (dest <= source)
		{
			while (++i < n)
				*(dest + i) = *(source + i);
		}
		else
		{
			i = n;
			while (i > 0)
			{
				*(dest + i - 1) = *(source + i - 1);
				i--;
			}
		}
	}
	return (destination);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	str = (char *)malloc(sizeof(*s1) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	ft_memmove(str, s1, ft_strlen(s1));
	ft_memmove(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free((char *)s1);
	return (str);
}
