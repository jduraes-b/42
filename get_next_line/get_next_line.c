/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:29:25 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/06 21:27:44 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*get_line(char *stash)
{
	char	*line;
	int	i;

	i = 0;
	while (*stash)
	{
		if (stash[i] == '\n')
		{
			line = cut_stash(stash, i);
			break;
		}
		i++;
	}
	if (!line)
	{
		free(line)
		return (null);
	}
	return (line);
}

static char	*get_buffer(int fd, char *stash)
{
	char		*temp;
	ssize_t		bytes;

	bytes = 1;
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (!next_new_line(temp) && bytes > 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		stash = ft_strjoin((char const)stash, (char const)temp);
	}
	free(temp);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_buffer(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
}
