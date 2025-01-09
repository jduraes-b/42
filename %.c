/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:41:04 by jduraes-          #+#    #+#             */
/*   Updated: 2024/06/27 18:43:49 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

int	main(int argc, char **argv)
{
	int a;
	int b;
	int c;

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		c = a % b;
		printf("%d p %d = %d \n", a, b, c);
	}
	else
		write(1, "\n", 1);
}
