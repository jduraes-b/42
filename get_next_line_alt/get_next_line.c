/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:29:25 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/11 22:03:46 by jduraes-         ###   ########.fr       */
/*       ne = get_line(fd, stash                                                                     */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_buffer(int fd, char **stash, int *run)
{
	char	*temp;
	ssize_t	bytes;

	bytes = 1;
	*run = 1;
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
	*stash = ft_strjoin(*stash, temp);
	if (bytes == 0)
		*run = 0;
	free(temp);
	return (*stash);
}

static char	*get_line(int fd, char **stash)
{
	char	*line;
	int	run;
	int	end;

	line = NULL;
	end = 0;
	run = 1;
	while (analyze(stash) == -1 && run)
		*stash = get_buffer(fd, stash, &run);
	if (run == 0)
		return (*stash);
	end = analyze(stash);
	line = cut_stash(stash, end);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	static int	begin;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(begin == 0)
	{
		stash = malloc(1);
		stash[0] = '\0';
		begin = 1;
	}
	line = get_line(fd, &stash);
	if (!stash)
		return (NULL);
	return (line);
}
