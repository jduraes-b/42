/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:31:02 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/10 19:53:38 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **s)
{
	if (maxnr(s) == (*s)->next->next->number && !issorted(*s))
		sa(s);
	else if (maxnr(s) == (*s)->number)
	{
		ra(s);
		if (!issorted(*s))
			sa(s);
	}
	else
	{
		if (maxnr(s) == (*s)->next->number)
			rra(s);
		if (!issorted(*s))
			sa(s);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (ps_lstsize(a) > 3)
		pb(a, b);
	refresh(a, b);
	if (!issorted(*a))
		sort_three(a);
	sort(a, b);
}

void	sort(t_stack **a, t_stack **b)
{
	t_stack	*curr;

	curr = *b;
	while (*b)
	{
		refresh(a, b);
		cost(a, b);
		curr = cheapest(b);
		whatmove(a, b, curr);
	}
}

void	whatmove(t_stack **a, t_stack **b, t_stack *curr)
{
	if (case_1(a, b, curr))
		;
	else if (case_2(a, b, curr))
		;
	else if (case_3(a, b, curr))
		;
	else if (case_4(a, b, curr))
		;
	else if (case_5(a, b, curr))
		;
	else if (case_6(a, b, curr))
		;
	else if (case_7(a, b, curr))
		;
}
