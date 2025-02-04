/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:16:13 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/15 17:28:34 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fillstash(int fd, char **stash, int *end)
{
	char	*temp;
	ssize_t	bytes;

	bytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (analyze(stash, &end) == -1 && bytes > 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			free(*stash);
			return (NULL);
		}
		temp[bytes] = '\0';
		*stash = ft_strjoin(*stash, temp);
	}
	free(temp);
	if (ft_strlen(*stash) != 0)
		return (*stash);
	free(*stash);
	return (NULL);
}

char	*get_line(char **stash, int end)
{
	char	*line;
	int		i;
	int		newstashsize;

	i = 0;
	line = malloc(sizeof(char) * (end + 1));
	while (i <= end)
	{
		line[i] = (*stash)[i];
		i++;
	}
	line[i] = '\0';
	newstashsize = ft_strlen(*stash) - end;
	*stash = clean_stash(stash, end, newstashsize);
	if (ft_strlen(line) > 0)
		return (line);
	free(line);
	free(*stash);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash[FOPEN_MAX];
	char		*nextline;
	int			end;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	end = 0;
	if (stash[fd] == NULL)
	{
		stash[fd] = malloc(sizeof(char) * 1);
		stash[fd][0] = '\0';
	}
	stash[fd] = fillstash(fd, &stash[fd], &end);
	if (!stash[fd])
		return (NULL);
	nextline = get_line(&stash[fd], end);
	return (nextline);
}
