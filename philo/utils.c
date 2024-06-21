/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:51:24 by jduraes-          #+#    #+#             */
/*   Updated: 2024/06/21 17:46:11 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while(str[++i])
		;
	return (i);
}

int	rest(t_philo *philo)
{
	if (!action(philo, "is sleeping"))
		return (0);
	usleep(philo->table->tts * 1000);
	return (1);
}

int	eat(t_philo *philo)
{
	if (!action(philo, "is eating"))
	{
		pthread_mutex_unlock(&philo->table->forkmut[philo->nr - 1]);
        pthread_mutex_unlock(&philo->table->forkmut[philo->nr % philo->table->pc]);
		return (0);
	}
	pthread_mutex_lock(&philo->table->restum);
	philo->le = get_time();
	if (philo->hunger)
		philo->hunger--;
	usleep(philo->table->tte * 1000);
	pthread_mutex_unlock(&philo->table->restum);
	pthread_mutex_unlock(&philo->table->forkmut[philo->nr - 1]);
    pthread_mutex_unlock(&philo->table->forkmut[philo->nr % philo->table->pc]);
	return (1);
}

int	single(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forkmut[philo->nr - 1]);
	action(philo, "has taken a fork");
	while (1)
	{
		pthread_mutex_lock(&philo->table->restum);
		if (!philo->table->ff)
			pthread_mutex_unlock(&philo->table->restum);
		else
			break ;
	}
	pthread_mutex_unlock(&philo->table->restum);
	pthread_mutex_unlock(&philo->table->forkmut[philo->nr]);
	return (0);
}

int	alive(t_philo *philo)
{
	//pthread_mutex_lock(&philo->table->restum);
	if (get_time() - philo->le > philo->table->ttd)
	{
		action(philo, "died");
		//pthread_mutex_unlock(&philo->table->restum);
		return (0);
	}
	else if (philo->hunger == 0)
	{
		action(philo, "finished");
		//pthread_mutex_unlock(&philo->table->restum);
		return (0);
	}
	//else
	//	pthread_mutex_unlock(&philo->table->restum);
	return (1);
}

void	error(char *str, t_table *table)
{
    write(2, str, ft_strlen(str));
    write(2, "\n", 1);
	clean_table(table);
    exit(1);
}

int	action(t_philo *philo, char *str)
{
	long long	time;

	pthread_mutex_lock(&philo->table->restum);
	if (philo->table->ff)
	{
		pthread_mutex_unlock(&philo->table->restum);
        return (0);
	}
	time = get_time() - philo->table->stime;
	pthread_mutex_lock(&philo->table->restum);
	printf("%lld %d %s\n", time, philo->nr, str);
	pthread_mutex_unlock(&philo->table->restum);
	return (1);
}

long long	get_time(void)
{
	struct timeval    tv;

gettimeofday(&tv, NULL);
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
