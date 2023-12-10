/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:03:22 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/28 17:56:36 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*cheapest(t_stack **s)
{
	t_stack	*curr;
	t_stack	*cheapest;
	int	temp;
		
	curr = *s;
	temp = curr->cost;
	cheapest = curr;
	while (curr)
	{
		if (curr->cost < temp)
		{
			cheapest = curr;
			temp = curr->cost;
		}
		curr = curr->next;
	}
	return (cheapest);
}

void	case_11a(t_stack *curr, t_stack **s, t_stack **t)
{
	while (curr->sprice && curr->tprice)
	{
		rr(s, t);
		curr->sprice--;
		curr->tprice--;
	}
	while (curr->sprice)
	{
		ra(s);
		curr->sprice--;
	}
	while (curr->tprice)
	{
		rb(t);
		curr->tprice--;
	}
	pb(s, t);
}

void	case_22a(t_stack *curr, t_stack **s, t_stack **t)
{
	curr->sprice = ps_lstsize(*s) - curr->sprice;
	curr->tprice = ps_lstsize(*t) - curr->tprice;
	while (curr->sprice && curr->tprice)
	{
		rrr(s, t);
		curr->sprice--;
		curr->tprice--;
	}
	while (curr->sprice)
	{
		rra(s);
		curr->sprice--;
	}
	while (curr->tprice)
	{
		rrb(t);
		curr->tprice--;
	}
	pb(s, t);
}

void	case_12a(t_stack *curr, t_stack **s, t_stack **t)
{
	curr->tprice = ps_lstsize(*t) - curr->tprice;
	while (curr->sprice)
	{
		ra(s);
		curr->sprice--;
	}
	while (curr->tprice)
	{
		rrb(t);
		curr->tprice--;
	}
	pb(s, t);
}

void	case_21a(t_stack *curr, t_stack **s, t_stack **t)
{
	curr->sprice = ps_lstsize(*s) - curr->sprice;
	while (curr->sprice)
	{
		rra(s);
		curr->sprice--;
	}
	while (curr->tprice)
	{
		rb(s);
		curr->tprice--;
	}
	pb(s, t);
}
