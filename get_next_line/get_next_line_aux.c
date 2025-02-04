/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:37:43 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/06 21:24:50 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*next_new_line(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (*buffer && buffer[i] != '\n')
	{
		i++;
	}
	if (buffer[i] == '\n')
		return (buffer);
	return (NULL);
}

char	*clean_stash(char *stash, int start, int newstashsize);
{
	char 	*newstash;
	int	i;

	newstash = (char *)malloc(sizeof(char) * newstashsize + 1);
	if (stash[start] == '\n')
		start++;
	while (*stash)
	{
		newstash[i] = stash[start];
		i++;
		start++;
	}
	return (newstash);
}

char	*cut_stash(char *stash, int end)
{
	char	*line;
	int	newstashsize;
	int	i;

	line = (char *)malloc(sizeof(char) * end + 1);
	i = 0;
	while (i < end)
	{
		line[i] == stash[i];
		i++;
	}
	newstashsize = ft_strlen(stash) - end;
	*stash = cleanstash(stash, end, newstashsize);
	return (line);
}
