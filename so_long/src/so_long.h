/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:01:38 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/30 19:19:26 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_imgs
{
	void	*player;
	void	*wall;
	void	*col;
	void	*exit;
}	t_imgs;

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	char**	map;
	int	xlen;
	int	ylen;
	int	c;
	t_position	*player;
	t_imgs	*img;
}	t_data;

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

int	wrongargs(int argc, char** argv);
int	mapread(char *file, t_data *gamestate);
int	mapwrite(int fd, t_data *gamestate);
int	mapcheck(t_data *gamestate);
int	playercheck(t_data *gamestate);
int	wallcheck(t_data *gamestate);
int	pathcheck(t_data *gamestate);
int	flood_fill(t_data *gamestate, int x, int y, char** map);
void	mlxstart(t_data *gamestate);
void	setimgs(t_data *gamestate, int size);
void	maprender(t_data gamestate);

#endif