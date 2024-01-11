/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:06:07 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/24 18:57:07 by jduraes-         ###   ########.fr       */
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

void	sort_to_three(t_stack **s, t_stack **t)
{
	t_stack	*curr;
	
	curr = *s;
	while (ps_lstsize(*s) > 3)
	{
		refresh(s, t);
		setcosts(s, t);
		curr = cheapest(s);
		applya(curr, s, t);
	}
}

void	applya(t_stack *curr, t_stack **s, t_stack **t)
{
	if (curr->half == 11)
		case_11a(curr, s, t);
	else if (curr->half == 12)
		case_12a(curr, s, t);
	else if (curr->half == 21)
		case_21a(curr, s, t);
	else if (curr->half == 22)
		case_22a(curr, s, t);	
}

void	applyb(t_stack *curr, t_stack **s, t_stack **t)
{
	if (curr->half == 11)
		case_11b(curr, s, t);
	else if (curr->half == 12)
		case_12b(curr, s, t);
	else if (curr->half == 21)
		case_21b(curr, s, t);
	else if (curr->half == 22)
		case_22b(curr, s, t);	
}
