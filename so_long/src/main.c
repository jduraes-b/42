/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:18:41 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/24 20:45:24 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wrongargs(int argc, char** argv)
{
	if (argc == 2)
	{
		if (!ft_strstr(ft_substr(argv[1], (ft_strlen(argv[1]) - 4), 4), ".ber"))
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
	t_data	*gamestate;
	t_position	*player;

	if (wrongargs(argc, argv))
		return (1);
	gamestate = (t_data *)malloc(sizeof(t_data));
	player = (t_position *)malloc(sizeof(t_position));
	gamestate->player = player;
	if(!mapread(argv[1], gamestate))
	{
		write(1, "map read error", 14);
		return (1);
	}
	if(!mapcheck(gamestate))
		return (0);
}
