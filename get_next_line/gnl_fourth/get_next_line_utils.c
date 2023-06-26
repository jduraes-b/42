/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:51:34 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/15 19:33:17 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlenplus(char *s, char c)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	if (!s)
		return (0);
	while (s[ii] != '\0')
		ii++;
	while (s[i] != c && i <= ii)
		i++;
	if (c == '\n' && i < ii)
		return (i);
	else if (c == '\n')
		return (-1);
	return (ii);
}

char	*ft_memmove(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	if (dst > src)
	{
		while (len-- > 0)
			dst[len] = src[len];
	}
	else
	{
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		ii;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlenplus(s1, '\0') + ft_strlenplus(s2,
					'\0') + 1));
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
