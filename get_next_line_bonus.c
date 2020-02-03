/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <mlaplana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:57:28 by mlaplana          #+#    #+#             */
/*   Updated: 2019/12/06 17:16:11 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

static int	ft_get_line(char **memory, char **line, int n_bytes)
{
	char *aux1;
	char *aux2;

	if (n_bytes < 0)
		return (-1);
	if (!*memory && !n_bytes)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((aux1 = ft_strchr(*memory, '\n')))
	{
		*aux1 = 0;
		*line = ft_strdup(*memory);
		aux2 = ft_strdup(++aux1);
		free(*memory);
		*memory = aux2;
	}
	else
	{
		*line = *memory;
		*memory = NULL;
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*memory[4096];
	int			n_bytes;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((n_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[n_bytes] = 0;
		if (!memory[fd])
			memory[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(memory[fd], buff);
			free(memory[fd]);
			memory[fd] = tmp;
		}
		if (ft_strchr(memory[fd], '\n'))
			break ;
	}
	return (ft_get_line(&memory[fd], line, n_bytes));
}
