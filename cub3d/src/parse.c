/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:41:14 by jduraes-          #+#    #+#             */
/*   Updated: 2024/07/16 23:23:46 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

t_gs	*gs_init(void)
{
	t_gs    *gs;

    gs = (t_gs *)ft_calloc(1, sizeof(t_gs));
    if (!gs)
        ft_perror("gamestate init error", 1);
    return (gs);
}

static int	info_write(char *f, t_gs *gs)
{

}

int	parser(char *f, t_gs *gs)
{
	int        fd;
	int	ic;
	char	*line;

	ic = 0;
    fd = open(f, O_RDONLY);
	line = get_next_line(fd);
	ic++;
	gs->xlen = 0;
	while (line)
	{
		free(line);
		ic++;
		line = get_next_line(fd);
		if (ic > 8 && ft_strlen(line) > gs->xlen)
			gs->xlen = ft_strlen(line);
			
		gs->ylen = ic - 8;
	}
	if (gs->ylen < 3 || gs->xlen < 3)
		ft_perror("Invalid map", 1);
	free(line);
	return (info_write(f, gs));
}