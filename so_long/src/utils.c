/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:48:36 by jduraes-          #+#    #+#             */
/*   Updated: 2024/02/03 17:57:04 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freegamestate(t_data *gamestate)
{
	doublefree(gamestate->map);
	free(gamestate->player);
	free(gamestate->exit);
	free(gamestate->img);
	free(gamestate);
}

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

t_data*	initialize()
{
	t_data	*gamestate;
	t_position	*player;
	t_position	*exit;
	t_imgs	*img;

	gamestate = (t_data*)ft_calloc(1, sizeof(t_data));
	player = (t_position*)ft_calloc(1, sizeof(t_position));
	gamestate->player = player;
	img = (t_imgs*)ft_calloc(1, sizeof(t_imgs));
	gamestate->img = img;
	exit = (t_position*)ft_calloc(1, sizeof(t_position));
	gamestate->exit = exit;
	return (gamestate);
}
