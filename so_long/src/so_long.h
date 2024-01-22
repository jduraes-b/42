/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:01:38 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/22 21:17:41 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_list
{
	void	*content;
	struct s_list *next;
}	t_list;

struct	gamestate
{
	char**	map;
	int	xlen;
	int	ylen;
	struct	player
	{
		int	x;
		int	y;
	}
}

# ifndef BUFFER_SIZE
#  define MAX_LINE_LENGTH 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307

#endif
