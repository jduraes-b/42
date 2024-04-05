/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:51:24 by jduraes-          #+#    #+#             */
/*   Updated: 2024/04/05 19:13:13 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	char	*str;
	size_t	 i;

	p = malloc(nmemb * size);
	if (p == NULL)
	 	return (NULL);
	str = p;
	while (i < nmemb * size)
		str[i++] = '\0';
	return (p);
}

int	philo_atoi(char *s)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	if (s[i] == '+')
		i++;
	while (s[i]  >=  '0' && s[i] <= '9')
		r = r * 10 + (s[i++] - '0');
	if (s[i] != '\0')
		return (-1);
	return (r);
}
