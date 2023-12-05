/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:02:05 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/13 18:01:19 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **root)
{
	t_stack	*temp;

	temp = (*root);
	*root = (*root)->next;
	temp->next = (*root)->next;
	(*root)->next = temp;
}

void	sa(t_stack **a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	sb(t_stack **b)
{
	write(1, "sb\n", 3);
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}

void	rra(t_stack **a)
{
	write(1, "rra\n", 4);
	rrotate(a);
}
