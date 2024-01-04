/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:28:30 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/03 20:13:16 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **s, t_stack **t)
{
	t_stack	*temp;

	temp = *s;
	*s = (*s)->next;
	temp->next = *t;
	*t = temp;
}

void	swap(t_stack **root)
{
	t_stack	*temp;

	temp = *root;
	*root = (*root)->next;
	temp->next = (*root)->next;
	(*root)->next = temp;
}

void	rotate(t_stack **root)
{
	t_stack	*temp;
	t_stack	*curr;

	temp = *root;
	*root = (*root)->next;
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
}

void	rrotate(t_stack **root)
{
	t_stack	*curr;
	t_stack	*temp;

	curr = *root;
	temp = *root;
	while (curr->next != NULL)
		curr = curr->next;
	while (temp->next != curr)
		temp = temp->next;
	curr->next = *root;
	*root = curr;
	temp->next = NULL;
}

void	rr(t_stack **a, t_stack **b)
{
	if (ps_lstsize(a) < 3)
		swap(a);
	else
		rotate(a);
	if (ps_lstsize(b) < 3)
		swap(b);
	else
		rotate(b);
	write(1, "rr\n", 3);
}
