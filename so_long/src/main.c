/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:18:41 by jduraes-          #+#    #+#             */
/*   Updated: 2024/02/03 17:55:51 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	gg(t_data *gamestate)
{
	deinitialize(gamestate);
	exit(EXIT_SUCCESS);
	return (0);
}

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
	/*t_position	*player;
	t_position	*exit;
	t_imgs	*img;*/

	if (wrongargs(argc, argv))
		return (1);
	/*gamestate = (t_data *)malloc(sizeof(t_data));
	player = (t_position *)malloc(sizeof(t_position));
	gamestate->player = player;
	img = (t_imgs *)malloc(sizeof(t_imgs));
	gamestate->img = img;
	exit = (t_position *)malloc(sizeof(t_position));
	gamestate->exit = exit;
	gamestate->moves = 0;*/
	gamestate = initialize();
	if(!mapread(argv[1], gamestate))
	{
		write(1, "map read error", 14);
		deinitialize(gamestate);
		return (1);
	}
	if(!mapcheck(gamestate))
	{
		write(1, "unacceptable map", 16);
		deinitialize(gamestate);
		return (0);
	}
	mlxstart(gamestate);
}
