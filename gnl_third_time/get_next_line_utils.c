/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:26:07 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/15 17:06:03 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	free(s1);
	str[i] = '\0';
	return (str);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	analyze(char **stash, int **i)
{
	**i = 0;
	if (!(*stash))
		return (-1);
	while ((*stash)[**i])
	{
		if ((*stash)[**i] == '\n')
		{
			return (**i);
		}
		(**i)++;
	}
	return (-1);
}

char	*clean_stash(char **stash, int start, int newstashsize)
{
	int			i;
	static char	*new;

	i = 0;
	new = malloc(sizeof(char) * newstashsize);
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
