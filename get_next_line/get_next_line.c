/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:29:25 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/11 18:36:21 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_buffer(int fd, char *stash)
{
	char	*temp;
	ssize_t	bytes;

	bytes = 1;
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes = read(fd, temp, BUFFER_SIZE);
	if (bytes == -1)
	{
		free(temp);
		return (NULL);
	}
	temp[bytes] = '\0';
	stash = ft_strjoin(stash, temp);
	free(temp);
	return (stash);
}

static char	*get_line(int fd, char *stash, char *line)
{
	int		i;
	int	linebreak;

	i = 0;
	linebreak = 0;
	stash = get_buffer(fd, stash);
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			linebreak = 1;
			line = cut_stash(stash, i);
			if (!line)
			{
				free(line);
				return (NULL);
			}
			break ;
		}
		i++;
	}
	if (!linebreak)
		get_line(fd, stash, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		return (NULL);
	line = get_line(fd, stash, line);
	return (line);
}