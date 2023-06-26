/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:41:17 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/15 19:28:38 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **stash)
{
	char	*line;
	int		end;
	int		newstashsize;

	end = ft_strlenplus(*stash, '\n') + 1;
	newstashsize = ft_strlenplus(*stash, '\0') - end;
	line = ft_substr((*stash), 0, end);
	*stash = ft_memmove(*stash, &((*stash)[end]), newstashsize - 1);
	(*stash)[newstashsize] = '\0';
	return (line);
}

static char	*fillstash(int fd, char **stash)
{
	char	*temp;
	ssize_t	bytes;

	bytes = 1;
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (ft_strlenplus(*stash, '\n') == -1 && bytes > 0)
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
	if (ft_strlenplus(*stash, '\0') != 0)
		return (*stash);
	free(*stash);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	if (stash[fd] == NULL)
	{
		stash[fd] = malloc(sizeof(char) * 1);
		stash[fd][0] = '\0';
	}
	stash[fd] = fillstash(fd, &stash[fd]);
	if (!stash[fd])
		return (NULL);
	return (get_line(&stash[fd]));
}
