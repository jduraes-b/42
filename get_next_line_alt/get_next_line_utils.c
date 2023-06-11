/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:37:43 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/11 22:00:31 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		ii;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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

char	*clean_stash(char **stash, int start, int newstashsize)
{
	int		i;
	static char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * newstashsize);
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

	line = (char *)malloc(sizeof(char) * end + 1);
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
