/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:24:58 by jduraes-          #+#    #+#             */
/*   Updated: 2024/07/16 23:21:43 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	is_valid(char *f)
{
	int	fd;
	int	i;

	i = -1;
	while (f[++i] != '.' && f[i] != '\0')
	{
		if (f[i] == '\0')
		    ft_perror("Invalid map format", 1);
	}
	if (ft_strncmp(f + i, ".cub", 4))
		ft_perror("Invalid map format", 1);
	fd = open(f, O_RDONLY);
	if (fd == -1)
		ft_perror("Map doesnt exist", 1);
}

int	main(int argc, char **argv)
{
	t_gs	*gs;
	if (argc != 2)
		ft_perror("wrong number of arguments", 1);
	is_valid(argv[1]);
	gs = gs_init();
	parser(gs);
	return (0);
}