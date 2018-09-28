/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolomo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:26:41 by csolomo           #+#    #+#             */
/*   Updated: 2018/08/23 12:45:18 by csolomo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	readline(const int fd, char **save)
{
	char		buff[BUFF_SIZE + 1];
	char		*free_me;
	int			bytes;

	if ((bytes = read(fd, buff, BUFF_SIZE)) < 0)
		return (-1);
	buff[bytes] = '\0';
	free_me = *save;
	*save = ft_strjoin(*save, buff);
	free(free_me);
	return (bytes);
}

int			get_next_line(const int fd, char **line)
{
	static char	*save;
	char		*tmp;
	char		*free_me;
	int			bytes;

	if (!save)
		save = ft_strnew(BUFF_SIZE);
	if (!line || fd < 0 || read(fd, save, 0))
		return (-1);
	while (!(tmp = ft_strchr(save, '\n')))
	{
		bytes = readline(fd, &save);
		if (bytes == 0 && ft_strlen(save) == 0)
			return (0);
		if (bytes == 0)
			save = ft_strjoin(save, "\n");
	}
	*line = ft_strsub(save, 0, ft_strlen(save) - ft_strlen(tmp));
	free_me = save;
	if (tmp && tmp + 1)
		save = ft_strdup(tmp + 1);
	else
		save = NULL;
	free(free_me);
	return (1);
}
