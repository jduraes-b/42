/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:54:43 by jduraes-          #+#    #+#             */
/*   Updated: 2024/06/19 22:05:43 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	oddfork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forkmut[philo->nr % philo->table->pc]);
    if (!action(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->table->forkmut[philo->nr % philo->table->pc]);
		return (1);
	}
	pthread_mutex_lock(&philo->table->forkmut[philo->nr - 1]);
	if (!action(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->table->forkmut[philo->nr - 1]);
		pthread_mutex_unlock(&philo->table->forkmut[philo->nr % philo->table->pc]);
		return (1);
	}
	return (0);
}

int	evenfork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forkmut[philo->nr - 1]);
	if (!action(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->table->forkmut[philo->nr - 1]);
		return (1);
	}
	pthread_mutex_lock(&philo->table->forkmut[philo->nr % philo->table->pc]);
    if (!action(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->table->forkmut[philo->nr % philo->table->pc]);
		pthread_mutex_unlock(&philo->table->forkmut[philo->nr - 1]);
		return (1);
	}

	return (0);
}

int	grabfork(t_philo *philo)
{
	if (philo->table->pc == 1)
		return (single(philo));
	else if (philo->nr % 2 == 0)
	{
		if (evenfork(philo))
			return (0);
		if (oddfork(philo))
			return (0);
	}
	return (1);
}

void *dinner(void *phil)
{
	t_philo    *philo;

    philo = (t_philo *)phil;
    while (1)
	{
		if (!grabfork(philo))
		    return (NULL);
    }
    return ;
}

int	start(t_table *table)
{
	int		i;
	i = -1;
	while (++i < table->pc)
	{
		if (pthread_create(&table->philos[i].thread, NULL, dinner, &table->philos[i]))
		    error("thread creation error", table);

	}
	monitoring(table);
	i = -1;
	while (++i < table->pc)
	{
		if (pthread_join(table->philos[i].thread, NULL))
            error("thread join error", table);
	}

}