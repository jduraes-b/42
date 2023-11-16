/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:23:37 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/15 19:51:48 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bottomhcost(int sprice, int tprice, int ssize, int tsize)
{
	if (tprice > tsize / 2)
	{
		if (sprice >= tprice)
			return ((tprice - tsize / 2) + ((sprice - ssize / 2) - (tprice - tsize / 2)));
		else
			return ((sprice - ssize / 2) + ((tprice - tsize / 2) - (sprice - ssize / 2)));
	}
	return ((sprice - ssize / 2) + tprice);
}

int	tophcost(int sprice, int tprice, int ssize, int tsize)
{
	(void) ssize;
	if (tprice <= tsize / 2)
	{
		if (sprice >= tprice)
			return (tprice + (sprice - tprice));
		else
			return (sprice + ((tprice - tsize / 2) - sprice));
	}
	return (sprice + tprice);
}

int	howmanyrotate(t_stack *s, t_stack **t)
{
	t_stack	*ts;
	t_stack	*tt;
	int	tsize;
	int	price;
	
	ts = s;
	tt = *t;
	price = 0;
	tsize = ps_lstsize(tt);
	while (tt)
	{
		if (ts->position == tt->position - 1)
			return (price);
		else
			{
				price++;
				tt = tt->next;
			}
	}
	return (price);
}

void	setcosts(t_stack **s, t_stack **t)
{
	int	ssize;
	int	sprice;
	int	tprice;
	t_stack	*curr;
	
	curr = *s;
	ssize = ps_lstsize(*s);
	sprice = 0;
	while (curr)
	{
		sprice = sprice + curr->position;
		tprice = howmanyrotate(curr, t);
		if (curr->position > (ps_lstsize(*s) / 2))
			curr->cost = tophcost(sprice, tprice, ps_lstsize(*s), ps_lstsize(*t));
		else
			curr->cost = bottomhcost(sprice, tprice, ps_lstsize(*s), ps_lstsize(*t));
		curr = curr->next;
	}
}
