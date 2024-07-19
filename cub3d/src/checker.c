/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:58:45 by jduraes-          #+#    #+#             */
/*   Updated: 2024/07/19 22:39:28 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_check(t_gs *gs, int i, int j)
{
	int	c;

	c = 0;
	while(gs->map[++i] != NULL)
	{
		j = -1;
        while(gs->map[i][++j]!= '\0')
        {
            if (gs->map[i][j] == 'N' || gs->map[i][j] == 'S' ||
				gs->map[i][j] == 'E' || gs->map[i][j] == 'W')
			{
				c++;
				gs->player->x = j;
				gs->player->y = i;
			}
        }
	}
	if (c != 1)
		ft_perror("map is only accpetable if it has 1 player", 1);
}

int	flood_fill(t_gs *gs, int x, int y, char **map)
{
	if (map[x][y] == '1')
		return (0);
	else if (map[x][y] == ' ')
		return (0);
	map[x][y] = '1';
	flood_fill(gs, x + 1, y, map);
	flood_fill(gs, x - 1, y, map);
	flood_fill(gs, x, y + 1, map);
	flood_fill(gs, x, y - 1, map);
	return (1);
}

static void	wall_check(t_gs *gs)
{
	char	**tmap;
	int	i;

	i = -1;
	tmap = calloc(gs->ylen + 1, sizeof(char **));
	tmap[gs->ylen] = NULL;
	while (++i < gs->ylen)
		tmap[i] = ft_strdup(gs->map[i]);
	if (!flood_fill(gs, gs->player->y, gs->player->x, tmap))
	{
		doublefree(tmap);
		ft_perror("map cant have holes in the wall");
	}
	else
		doublefree(tmap);
}

int	checker(t_gs *gs)
{
	player_check(gs, -1, -1);
	wall_check(gs);
}