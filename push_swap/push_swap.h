/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:59:31 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/13 18:27:53 by jduraes-         ###   ########.fr       */
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
void	rrotate(t_stack **root);
void	swap(t_stack **root);
void	push(t_stack **source, t_stack **target);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
#endif
