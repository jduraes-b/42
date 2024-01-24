/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:50:26 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/24 20:23:57 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mapwrite(int fd, t_data *gamestate)
{
	char *line;
	int	x;
	int	y;

	line = get_next_line(fd);
	x = 0;
	y = 0;
	gamestate->map = malloc(sizeof(char) * gamestate->xlen + 1);
	//gamestate->map[gamestate->xlen] = '\0';
	while(x < gamestate->xlen)
		gamestate->map[x++] = malloc(sizeof(char) * gamestate->ylen + 1);
	x = 0;
	while (x <= gamestate->xlen)
	{
		y = -1;
		while (++y <= gamestate->ylen)
			gamestate->map[x][y] = line[y];
		x++;
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
	gamestate->xlen = ft_strlen(line);
	gamestate->ylen = -1;
	while (line)
	{
		if ((int)ft_strlen(line) != gamestate->xlen)
			return (0);
		line = get_next_line(fd);
		gamestate->ylen++;
	}
	free(line);
	return (mapwrite(fd, gamestate));
}
