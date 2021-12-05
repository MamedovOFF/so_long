/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:39:17 by spurple           #+#    #+#             */
/*   Updated: 2021/12/04 23:48:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*buf;
	char			*str;
	int				end;
}	t_list;
char	*get_str(char *str);
char	*get_save_str(char *save);
size_t	ft_strlen(const char *str);
void	*ft_memmove(void *destination, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
int		n_chr(char *save);

#endif