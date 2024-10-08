/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:28:08 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/22 18:05:45 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_stash(char *stash)
{
	int	end;
	int	stash_len;
	int	i;

	end = ft_strlenplus(stash, '\n');
	if (!stash[end])
	{
		free(stash);
		return (NULL);
	}
	stash_len = ft_strlenplus(stash, 0);
	i = 0;
	while (i < stash_len - end)
	{
		stash[i] = stash[end + 1 + i];
		i++;
	}
	stash[i] = '\0';
	return (stash);
}

static char	*get_line(char *stash, int eof)
{
	char	*line;
	int		end;
	int		i;

	i = -1;
	if (eof)
		end = ft_strlenplus(stash, 0) + 1;
	else
		end = ft_strlenplus(stash, '\n') + 1;
	line = malloc(sizeof(char) * end + 1);
	if (!line)
		return (NULL);
	while (++i < end)
		line[i] = stash[i];
	line[i] = 0;
	return (line);
}

static char	*get_stash(int fd, char *stash, int *eof)
{
	char	*temp;
	int		bytes;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes = 1;
	while (ft_strlenplus(stash, '\n') == -1 && bytes > 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			free(stash);
			return (NULL);
		}
		temp[bytes] = 0;
		stash = ft_strjoin(stash, temp);
	}
	free(temp);
	if (bytes == 0)
		*(eof) = 1;
	if (ft_strlenplus(stash, 0) != 0)
		return (stash);
	free(stash);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			eof;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
	{
		stash = malloc(sizeof(char) * 1);
		stash[0] = 0;
	}
	eof = 0;
	stash = get_stash(fd, stash, &eof);
	if (!stash)
		return (NULL);
	line = get_line(stash, eof);
	if (!eof)
		stash = clean_stash(stash);
	else
		stash[0] = 0;
	if (!stash)
		return (NULL);
	return (line);
}


int	main(int argc, char **argv)
{
	char	*line;
	int	fd;
	
	(void) argc;
	fd = open(argv[1], O_RDONLY);
	line = "first";
	while (line)
	{
		write(1, line, ft_strlenplus(line, 0));
		line = get_next_line(fd);
	}
	return (0);
}
