/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:19:15 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/13 18:26:42 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **root)
{
	t_stack	*temp;
	t_stack	*curr;

	temp = *root;
	*root = (*root)->next;
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	curr->next->next = NULL;
}

void	rrotate(t_stack **root)
{
	t_stack	*temp;
	t_stack *curr;

	curr = *root;
	temp = *root;
	while (curr->next->next != NULL)
		curr = curr->next;
	*root = curr->next;
	(*root)->next = temp;
	curr->next = NULL;
}

void	ra(t_stack **a)
{
	write(1, "ra\n", 3);
	rotate(a);
}

void	rb(t_stack **b)
{
	write(1, "rb\n", 3);
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}
