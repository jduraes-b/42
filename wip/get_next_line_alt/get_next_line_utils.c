/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:37:43 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/12 20:45:00 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	size_t			total_size;
	void			*allocated_memory;
	unsigned char	*mem_ptr;
	size_t			bytes_written;

	total_size = num_elements * element_size;
	allocated_memory = malloc(total_size);
	if (allocated_memory != NULL)
	{
		mem_ptr = (unsigned char *)allocated_memory;
		bytes_written = 0;
		while (bytes_written < total_size)
		{
			mem_ptr[bytes_written] = 0;
			bytes_written++;
		}
	}
	return (allocated_memory);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*clean_stash(char **stash, int start, int newstashsize)
{
	int			i;
	static char	*new;

	i = 0;
	new = ft_calloc(newstashsize, sizeof(char));
	if ((*stash)[start] == '\n')
		start++;
	while ((*stash)[start])
	{
		new[i] = (*stash)[start];
		i++;
		start++;
	}
	new[i] = '\0';
	free(*stash);
	return (new);
}

char	*cut_stash(char **stash, int end)
{
	char	*line;
	int		newstashsize;
	int		i;

	line = ft_calloc((end + 1), sizeof(char));
	i = 0;
	while (i <= end)
	{
		line[i] = (*stash)[i];
		i++;
	}
	line[i] = '\0';
	newstashsize = ft_strlen(*stash) - end;
	*stash = clean_stash(stash, end, newstashsize);
	return (line);
}

int	analyze(char **stash)
{
	int	i;

	i = 0;
	while ((*stash)[i])
	{
		if ((*stash)[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
