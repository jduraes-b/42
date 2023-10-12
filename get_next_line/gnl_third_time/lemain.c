/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:34:48 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/20 19:28:31 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("\"%s\"\n", line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (0);
}
