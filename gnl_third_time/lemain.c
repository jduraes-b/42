/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:34:48 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/12 19:13:30 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	i = 10;
	fd = open("test.txt", O_RDONLY);
	while (i > 0)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		i--;
	}
	free(line);
	return (0);
}
