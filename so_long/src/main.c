/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:18:41 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/22 19:32:32 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wrongargs(int argc, char argv)
{
	if (argc == 2)
	{
		if (ft_substr(argv[1], ".ber", (ft_strlen(argv[1]) - 4)) == NULL)
		{
			write(1, "wrong arguments", 14);
			return (1);
		}
		return (0);
	}
	write(1, "wrong arguments", 14);
	return (1);
}

int	main(int argc, char** argv)
{
	if (wrongargs(argc, argv))
		return (1);
}
