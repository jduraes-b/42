/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:47:24 by jduraes-          #+#    #+#             */
/*   Updated: 2024/06/14 19:18:45 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int	nr;
	long long	le;
	pthread_t	thread;
	struct s_table    *table;
}	t_philo;

typedef struct	s_table
{
	int	pc;
	int	ttd;
	int	tte;
	int	tts;
	int hunger;
	long long t;
	pthread_mutex_t *forkmut;
	pthread_mutex_t restum;
	t_philo *philos;
}	t_table;

void	*ft_calloc(size_t nmemb, size_t size);
int	philo_atoi(char *s);
long long	get_time(void);
int	philostart(t_table *table);
void	clean_table(t_table *table);

#endif
