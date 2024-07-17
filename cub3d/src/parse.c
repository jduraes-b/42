/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:41:14 by jduraes-          #+#    #+#             */
/*   Updated: 2024/07/17 19:46:44 by jduraes-         ###   ########.fr       */
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

void	t_format(char *s, t_gs *gs)
{
	static int	i;
    
	i++;
	if(i == 1 && !ft_strncmp(s, "NO ./", 5))
		gs->no_t = ft_substr(s, 3, ft_strlen(s) - 3);
	else if(i == 2 && !ft_strncmp(s, "SO ./", 5))
		gs->so_t = ft_substr(s, 3, ft_strlen(s) - 3);
	else if(i == 3 && !ft_strncmp(s, "WE ./", 5))
		gs->we_t = ft_substr(s, 3, ft_strlen(s) - 3);
	else if(i == 4 && !ft_strncmp(s, "EA ./", 5))
		gs->ea_t = ft_substr(s, 3, ft_strlen(s) - 3);
	else
		ft_perror("Error\ntexture format error\nshould be: \"NO ./texture\"\n", 1);
}

void	get_textures(char *full, t_gs *gs)
{
	char	**textures;
	int    i;

	textures = ft_split(full, "\n");
	if (!textures[0] ||!textures[1] ||!textures[2] ||!textures[3])
		ft_perror("Error\nmissing texture info", 1);
	i = -1;
	while (textures[++i] != NULL)
		t_format(textures[i], gs);
	doublefree(textures);
	free(full);
}

static int	info_write(char *f, t_gs *gs)
{
	int	fd;
	int	i;
	char	*line;
	char	*temp;

	i = -1;
	fd = open(f, O_RDONLY);
	while (line && ++i < 4)
	{
		temp = ft_strjoinfree(temp, line, 3);
		line = get_next_line(line);
	}
	get_textures(temp, gs);
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
		ft_perror("Error\nInvalid map", 1);
	free(line);
	return (info_write(f, gs));
}