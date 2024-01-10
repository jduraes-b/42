/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:23:00 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/02 19:15:04 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	
	setbiggest(a);
	sendsmall(a, b);
	while (ps_lstsize(a) > 3)
		pb(a, b);
	refresh(a, b);
	sort_three(a);
	refresh(a, b);
	sort(a, b);
	refresh(a, b);
	temp = *a;
	while (!issorted(*a))
	{
		while (temp->biggest != -1)
			temp = temp->next;
		if (temp->position <= temp->dte)
			ra(a);
		else
			rra(a);
	}
}
