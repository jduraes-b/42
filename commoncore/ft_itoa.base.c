/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:17:56 by jduraes-          #+#    #+#             */
/*   Updated: 2023/04/28 19:03:25 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rstr(char *str)
{
	int	i;
	int	ii;
	char	temp;

	i = ft_strlen(str) - 1;
	ii = 0;
	while (i/2 > 0)
	{
		temp = str[i];
		str[i] = str[ii];
		str[ii] = temp;
		i--;
		i++;
	}
}

char	*ft_itoa(int n, char *str, int base)
{
	int	i;
	int	isnega;

	i = 0;
	isnega = 0;
	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	if (n < 0)
	{
		isnega = 1;
		n = -n;
	}
	while ((n / base) > 0)
	{
		if ((n % base) > 9)
			str[i] = (n % base) - 10 + 'a';
		if ((n % base) < 10)
			str[i] = (n % base) + '0';
		n = n / base;
		i++;
	}
	if (isnega)
		str[i++] = '-';
	str[i] = '\0';
	rstr(str);
	return (str);
}
