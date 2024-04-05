/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:47:24 by jduraes-          #+#    #+#             */
/*   Updated: 2024/04/05 19:31:39 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct	s_table
{
	int	philocount;
	int	ttd;
	int	tte;
	int	tts;
	int	gottaeat;
}	t_table;

void	*ft_calloc(size_t nmemb, size_t size);
int	philo_atoi(char *s);

#endif
