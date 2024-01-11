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
	if (ps_lstsize(*s) == 1)
		curr->sprice = 0;
	while (curr->sprice > 0 && curr->tprice > 0)
	{
		rr(s, t);
		curr->sprice--;
		curr->tprice--;
	}
	while (curr->sprice > 0)
	{
		rb(s);
		curr->sprice--;
	}
	while (curr->tprice > 0)
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
	if (ps_lstsize(*s) == 1)
		curr->sprice = 0;
	while (curr->sprice > 0 && curr->tprice > 0)
	{
		rrr(t, s);
		curr->sprice--;
		curr->tprice--;
	}
	while (curr->sprice > 0)
	{
		rrb(s);
		curr->sprice--;
	}
	while (curr->tprice > 0)
	{
		rra(t);
		curr->tprice--;
	}
	pa(t, s);
}

void	case_12b(t_stack *curr, t_stack **s, t_stack **t)
{
	if (curr->together)
		case_12together(curr, s, t);
	else
	{
		curr->tprice = ps_lstsize(*t) - curr->tprice;
		if (ps_lstsize(*s) == 1)
			curr->sprice = 0;
		while (curr->sprice > 0)
		{
			rb(s);
			curr->sprice--;
		}
		while (curr->tprice > 0)
		{
			rra(t);
			curr->tprice--;
		}
	}
	pa(t, s);
}

void	case_21b(t_stack *curr, t_stack **s, t_stack **t)
{
	if (curr->together)
		case_12together(curr, s, t);
	else
	{
		curr->sprice = ps_lstsize(*s) - curr->sprice;
		if (ps_lstsize(*s) == 1)
			curr->sprice = 0;
		while (curr->sprice > 0)
		{
			rrb(s);
			curr->sprice--;
		}
		while (curr->tprice > 0)
		{
			ra(t);
			curr->tprice--;
		}
	}
	pa(t, s);
}

void	case_21together(t_stack *curr, t_stack **s, t_stack **t)
{
	if (curr->together == 2)
	{
		curr->sprice = ps_lstsize(*s) - curr->sprice;
		while (curr->sprice && curr->tprice)
		{
			rrr(t, s);
			curr->sprice--;
			curr->tprice--;
		}
		while (curr->sprice)
		{
			curr->sprice--;
			rrb(t);
		}
		return ;
	}
	while (curr->sprice && curr->tprice)
	{
		rr(t, s);
		curr->sprice--;
		curr->tprice--;
	}
	while (curr->tprice)
	{
		curr->tprice--;
		ra(t);
	}
}

void	case_12together(t_stack *curr, t_stack **s, t_stack **t)
{
	if (curr->together == 2)
	{
		curr->sprice = ps_lstsize(*s) - curr->sprice;
		while (curr->sprice && curr->tprice)
		{
			rrr(t, s);
			curr->sprice--;
			curr->tprice--;
		}
		while (curr->sprice)
		{
			curr->sprice--;
			rrb(t);
		}
		return ;
	}
	while (curr->sprice && curr->tprice)
	{
		rr(t, s);
		curr->sprice--;
		curr->tprice--;
	}
	while (curr->tprice)
	{
		curr->tprice--;
		ra(t);
	}
}
