/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:15:57 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/12 17:34:17 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **source, t_stack **target)
{
	t_stack	*temp;

	temp = *source;
	*source = (*source)->next;
	temp->next = *target;
	*target = temp;
}

void	pa(t_stack **a, t_stack **b)
{
	ft_printf("pa\n");
	push(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_printf("pb\n");
	push(a, b);
}

void	rrb(t_stack **b)
{
	write(1, "rrb\n", 4);
	rrotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	rrotate(a);
	rrotate(b);
}
