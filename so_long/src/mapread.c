/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:50:26 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/29 19:55:39 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wallcheck(t_data *gamestate)
{
	int	i;

	i = 0;
	while (gamestate->map[0][i] == '1')
		i++;
	if (gamestate->map[0][i] != '\0')
		return (0);
	i = 0;
	while (gamestate->map[i])
	{
		if (gamestate->map[i][0] != '1' 
		|| gamestate->map[i][gamestate->xlen - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	playercheck(t_data *gamestate)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	j = 0;
	player = 0;
	while (gamestate->map[++i])
	{
		j = -1;
		while (gamestate->map[i][++j])
		{
			if (gamestate->map[i][j] == 'P')
			{
				gamestate->player->x = j;
				gamestate->player->y = i;
				player++;
			}
		}
	}
	if (!player)
		return (0);
	if (!wallcheck(gamestate) || !pathcheck(gamestate))
		return (0);
	return (1);
}

int	mapcheck(t_data *gamestate)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	j = 0;
	exit = 0;
	if (!playercheck(gamestate))
		return (0);
	while (gamestate->map[i])
	{
		j = 0;
		while (gamestate->map[i][j])
		{
			if (gamestate->map[i][j] == 'C')
				gamestate->c++;
			if (gamestate->map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (gamestate->c < 1 || exit != 1)
		return (0);
	return (1);
}

int	mapwrite(int fd, t_data *gamestate)
{
	char *line;
	int	x;
	int	y;

	line = get_next_line(fd);
	x = 0;
	y = 0;
	gamestate->map = malloc(sizeof(char*) * gamestate->ylen + 1);
	gamestate->map[gamestate->ylen] = NULL;
	while(y < gamestate->ylen)
	{
		gamestate->map[y] = malloc(sizeof(char) * gamestate->xlen + 1);
		gamestate->map[y][gamestate->xlen] = '\0';
		y++;
	}
	y = -1;
	while (gamestate->map[++y])
	{
		x = -1;
		while (++x < gamestate->xlen)
			gamestate->map[y][x] = line[x];
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	mapread(char *file, t_data *gamestate)
{
	int	fd;
	char	*line;
	int	i;

	fd = open(file, O_RDONLY);
	i = 0;
	if (fd == 1)
	{
		write(1, "map read error", 14);
		return (0);
	}
	line = get_next_line(fd);
	gamestate->xlen = ft_strlen(line) - 1;
	gamestate->ylen = 0;
	while (line)
	{
		if ((int)ft_strlen(line) - 1 != gamestate->xlen)
			return (0);
		free(line);
		line = get_next_line(fd);
		gamestate->ylen++;
	}
	free(line);
	fd = open(file, O_RDONLY);
	return (mapwrite(fd, gamestate));
}
