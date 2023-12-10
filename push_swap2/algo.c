/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:16:57 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/15 19:51:39 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stuff(t_stack **a, t_stack **b)
{
	goorno(*a);
	setbiggest(a);
	sendsmall(a, b);
	while (ps_lstsize(*a) > 3)
	{
		if ((*a)->biggest)
			ra(a);
		pb(a, b);
	}
	refresh(a, b);
	//setcosts(a, b);
	//sort_to_three(a, b);
	sort_three(a);
	refresh(a, b);
	cost_back(a, b);
	sort_back(b, a);
	if (up(a))
	{
		while (!issorted(*a))
			rra(a);
	}
	while (!issorted(*a))
		ra(a);
}

int	up(t_stack **a)
{
	t_stack	*curr;
	int	i;
	
	curr = *a;
	i = 0;
	while (!curr->biggest)
	{
		curr = curr->next;
		i++;
	}
	if (i > ps_lstsize(*a) / 2)
		return (1);
	return (0);
}
//405 247 243 -25 -199 77 -290 45 -172 -301
