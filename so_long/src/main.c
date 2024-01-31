/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:18:41 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/31 18:32:57 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deinitialize(t_data *gamestate)
{
	mlx_destroy_image(gamestate->mlx, gamestate->img->player);
	mlx_destroy_image(gamestate->mlx, gamestate->img->wall);
	mlx_destroy_image(gamestate->mlx, gamestate->img->col);
	mlx_destroy_image(gamestate->mlx, gamestate->img->exit);
	mlx_destroy_image(gamestate->mlx, gamestate->img->bg);
	mlx_destroy_window(gamestate->mlx, gamestate->mlx_win);
	mlx_destroy_display(gamestate->mlx);
	free(gamestate->mlx);
	freegamestate(gamestate);
	return (0);
}

int	gg(t_data *gamestate)
{
	deinitialize(gamestate);
	exit(EXIT_SUCCESS);
	return (0);
}

void	freegamestate(t_data *gamestate)
{
	doublefree(gamestate->map);
	free(gamestate->player);
	free(gamestate->exit);
	free(gamestate);
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
	t_position	*player;
	t_position	*exit;
	t_imgs	*img;

	if (wrongargs(argc, argv))
		return (1);
	gamestate = (t_data *)malloc(sizeof(t_data));
	player = (t_position *)malloc(sizeof(t_position));
	gamestate->player = player;
	img = (t_imgs *)malloc(sizeof(t_imgs));
	gamestate->img = img;
	exit = (t_position *)malloc(sizeof(t_position));
	gamestate->exit = exit;
	gamestate->moves = 0;
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
