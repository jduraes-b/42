/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:05:37 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/29 22:12:02 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_11b(t_stack *curr, t_stack **s, t_stack **t)
{
	while (curr->sprice && curr->tprice)
	{
		rr(s, t);
		curr->sprice--;
		curr->tprice--;
	}
	while (curr->sprice)
	{
		rb(s);
		curr->sprice--;
	}
	while (curr->tprice)
	{
		ra(t);
		curr->tprice--;
	}
	pa(t, s);
}

void	case_22b(t_stack *curr, t_stack **s, t_stack **t)
{
	curr->sprice = ps_lstsize(*s) - curr->sprice;
	curr->tprice = ps_lstsize(*t) - curr->tprice;
	while (curr->sprice && curr->tprice)
	{
		rrr(t, s);
		curr->sprice--;
		curr->tprice--;
	}
	while (curr->sprice)
	{
		rrb(s);
		curr->sprice--;
	}
	while (curr->tprice)
	{
		rra(t);
		curr->tprice--;
	}
	pa(s, t);
}

void	case_12b(t_stack *curr, t_stack **s, t_stack **t)
{
	curr->tprice = ps_lstsize(*t) - curr->tprice;
	while (curr->sprice)
	{
		rb(s);
		curr->sprice--;
	}
	while (curr->tprice)
	{
		rra(t);
		curr->tprice--;
	}
	pa(t, s);
}

void	case_21b(t_stack *curr, t_stack **s, t_stack **t)
{
	curr->sprice = ps_lstsize(*s) - curr->sprice;
	while (curr->sprice)
	{
		rrb(s);
		curr->sprice--;
	}
	while (curr->tprice)
	{
		ra(s);
		curr->tprice--;
	}
	pa(t, s);
}
