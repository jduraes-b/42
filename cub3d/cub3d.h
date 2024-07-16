/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:01:45 by jduraes-          #+#    #+#             */
/*   Updated: 2024/07/16 23:00:23 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "libft/libft.h"

typedef struct	s_gs
{
	char	**raw;
	char	**map;
	int        xlen;
	int        ylen;
	char	*no_t;
	char	*so_t;
	char	*ea_t;
	char	*we_t;
	int	floor_c;
	int	ceiling_c;
}				t_gs;

#endif