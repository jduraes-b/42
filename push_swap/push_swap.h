/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:59:31 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/06 18:34:47 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <string.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

typedef struct	s_stack
{
	int	number;
	int	position;
//	struct	s_stack	*prev;
	struct	s_stack	*next;
}	t_stack;

int	wrongargs(char **argv);
t_stack	*create_stack(int size, char** content);
void	rotate(t_stack **root);

#endif
