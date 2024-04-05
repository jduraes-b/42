/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:48:01 by jduraes-          #+#    #+#             */
/*   Updated: 2024/04/05 19:29:31 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	argcheck(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
		return (0);
	table->philocount = philo_atoi(argv[1]);
	table->ttd = philo_atoi(argv[2]);
	table->tte = philo_atoi(argv[3]);
	table->tts = philo_atoi(argv[4]);
	table->gottaeat = -1;
	if (argc == 6)
		table->gottaeat = philo_atoi(argv[5]);
	if (table->philocount < 1 || table->ttd < 1
		|| table->tte < 1 || table->tts < 1
		|| (argc == 6 && table->gottaeat < 1))
		return (0);
	return (1);
}

int	main(int argc, char** argv)
{
	t_table	*table;

	table = (t_table *)calloc(1, sizeof(t_table));
	if (!argcheck(argc, argv, table))
	{
		printf("wrong arguments\n");
		exit(1);
	}
	return (0);
}
