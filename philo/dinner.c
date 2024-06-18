/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:54:43 by jduraes-          #+#    #+#             */
/*   Updated: 2024/06/18 19:18:07 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *dinner(void *phil)
{
	t_philo    *philo;

    philo = (t_philo *)phil;
    while (1)
	{
		
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
		    error("thread creation error");

	}
}