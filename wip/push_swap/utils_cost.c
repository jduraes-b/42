/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:23:37 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/18 20:05:03 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bottomhcost(t_stack *curr, t_stack **s, t_stack **t)
{
	int	total;

	total = 0;
	if (curr->tprice > ps_lstsize(*t) / 2)
	{
		if ((ps_lstsize(*t) - curr->tprice) < (ps_lstsize(*s) - curr->sprice))
		{
			total = (1 + (ps_lstsize(*t) - curr->tprice));
			curr->half = 22;
		}
		else
		{
			total = (1 + (ps_lstsize(*s) - curr->sprice));
			curr->half = 22;
		}
	}
	else
	{
		total = (1 + (ps_lstsize(*s) - curr->sprice) + (curr->tprice));
		curr->half = 21;
	}
	return (total);
}

int	tophcost(t_stack *curr, t_stack **s, t_stack **t)
{
	int	total;
	
	(void) s;
	total = 0;
	if (curr->tprice <= ps_lstsize(*t) / 2)
	{
		if (curr->sprice < curr->tprice)
		{
			curr->half = 11;
			total = (1 + curr->tprice);
		}
		else
		{
			curr->half = 11;
			total = (1 + curr->sprice);
		}
	}
	else
	{
		curr->half = 12;
		total = (1 + curr->sprice + (ps_lstsize(*t) - curr->tprice));
	}
	return (total);
}
int	howmanyrotate(t_stack *s, t_stack **t)
{
	t_stack	*ts;
	t_stack	*tt;
	int		price;

	ts = s;
	tt = *t;
	price = 0;
	while (tt)
	{
		if (targetfindex(ts->f_index, tt, 'b') == tt->f_index)
			return (price);
		else
		{
			price++;
			tt = tt->next;
		}
	}
	return (price);
}

int	targetfindex(int sfindex, t_stack *t, char list)
{
	t_stack	*curr;
	int		temp;

	curr = t;
	temp = -1;
	while (curr && list == 'b')
	{
		if (curr->f_index < sfindex && (temp == -1 || curr->f_index > temp))
			temp = curr->f_index;
		curr = curr->next;
	}
	temp = -1;
	while (curr && list == 'a')
	{
		if (curr->f_index > sfindex && (temp == -1 || curr->f_index < temp))
			temp = curr->f_index;
		curr = curr->next;
	}
	return (temp);
}

void	setcosts(t_stack **s, t_stack **t)
{
	t_stack	*curr;

	curr = *s;
	curr->sprice = 0;
	while (curr)
	{
		refresh(s, t);
		curr->sprice = curr->position;
		curr->tprice = howmanyrotate(curr, t);
		if (curr->sprice < (ps_lstsize(*s) / 2))
			curr->cost = tophcost(curr, s, t);
		else
			curr->cost = bottomhcost(curr, s, t);			
		curr = curr->next;
	}
}
