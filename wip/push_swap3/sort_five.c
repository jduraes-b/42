/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:13:21 by jduraes-          #+#    #+#             */
/*   Updated: 2023/12/19 19:37:02 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **a, t_stack **b)
{
	while (ps_lstsize(*a) > 3)
		pb(a, b);
	refresh(a, b);
	if (!issorted(*a))
		sort_three(a);
	while (*b)
	{
		refresh(a, b);
		cost_back(a, b);
		applyb(cheapest(b), b, a);
	}
	refresh(a, b);
	if (!issorted(*a))
		sort_five_2(a);
}

void	sort_five_2(t_stack **a)
{
	t_stack	*curr;
	curr = *a;
	while (curr->biggest != -1)
		curr = curr->next;
	if ((curr->position < ps_lstsize(*a) / 2 && ps_lstsize(*a) % 2 == 0) ||
		(curr->position < (ps_lstsize(*a) / 2 + 1) && ps_lstsize(*a) % 2 == 1))
	{
		while (!issorted(*a))
			ra(a);
	}
	else
		while (!issorted(*a))
			rra(a);
}
