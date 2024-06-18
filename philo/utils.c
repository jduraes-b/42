/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:51:24 by jduraes-          #+#    #+#             */
/*   Updated: 2024/06/18 19:18:09 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->restum);
	if (get_time() - philo->le > philo->table->ttd)
	{
		action(philo, "died");
		pthread_mutex_unlock(&philo->table->restum);
		return (0);
	}
	else if (philo->hunger == 0)
	{
		action(philo, "finished");
		pthread_mutex_unlock(&philo->table->restum);
		return (0);
	}
	pthread_mutex_unlock(&philo->table->restum);
	return (1);
}

void	error(char *str)
{
    write(2, str, ft_strlen(str));
    write(2, "\n", 1);
	clean_table();
    exit(1);
}

void	action(t_philo *philo, char *str)
{
	long long	time;

	pthread_mutex_lock(&philo->table->restum);
	time = get_time() - philo->table->stime;
	printf("%lld %d %s\n", time, philo->nr, str);
	pthread_mutex_unlock(&philo->table->restum);
}

long long	get_time(void)
{
	struct timeval    tv;

    if (gettimeofday(&tv, NULL) == NULL)
		return (-1);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	char	*str;
	size_t	 i;

	i = 0;
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
