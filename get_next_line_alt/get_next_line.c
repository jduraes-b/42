/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:29:25 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/13 20:11:11 by jduraes-         ###   ########.fr       */
/*       ne = get_line(fd,
		stash                                                                     */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		ii;
	char	*str;

	i = 0;
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), (sizeof(char)));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	ii = 0;
	while (s2[ii])
	{
		str[i] = s2[ii];
		i++;
		ii++;
	}
	str[i] = '\0';
	return (str);
}

static char	*get_buffer(int fd, char **stash, int *run)
{
	char	*temp;
	ssize_t	bytes;

	bytes = 1;
	temp = ft_calloc((BUFFER_SIZE + 1), (sizeof(char)));
	if (!temp)
		return (NULL);
	bytes = read(fd, temp, BUFFER_SIZE);
	if (bytes == -1)
	{
		free(temp);
		free(*stash);
		return (NULL);
	}
	temp[bytes] = '\0';
	*stash = ft_strjoin(*stash, temp);
	free(temp);
	if (!(*stash))
	{
		free(*stash);
		return (NULL);
	}
	if (bytes == 0)
		*run = 0;
	return (*stash);
}

static char	*get_line(int fd, char **stash)
{
	int		run;
	int		end;

	end = 0;
	run = 1;
	while (analyze(stash) == -1 && run)
		*stash = get_buffer(fd, stash, &run);
	if (run == 0)
		return (*stash);
	end = analyze(stash);
	return (cut_stash(stash, end));
}

char	*get_next_line(int fd)
{
	static char	*stash;
	static int	begin;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (begin == 0)
	{
		stash = ft_calloc(1, (sizeof(char)));
		stash[0] = '\0';
		begin = 1;
	}
	if (!stash)
		return (NULL);
	line = get_line(fd, &stash);
	return (line);
}
