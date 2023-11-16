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

void	setcosts(t_stack **s, t_stack **t)
{
	int	ssize;
	int	sprice;
	int	tprice;
	t_stack	temp;
	t_stack	*curr;
	
	curr = *s;
	ssize = ps_lstsize(*a);
	sprice = 1;
	while (curr)
	{
		sprice = sprice + curr->position;
		tprice = howmanyrotate(curr, t);
		curr->cost = getfinalprice(sprice, tprice, (ps_lstsize(*s), ps_lstsize(*t));
		curr = curr->next;
	}
}

int	getfinalcost(int sprice, int tprice, int ssize, int tsize)
{	
	if (sprice > ssize / 2)
	{
		if (tprice > tsize / 2)
		{
			sprice = ssize - sprice;
			tprice = tsize - tprice;
			return (sprice + (ft_av(sprice - tprice) + 1);
		}
		else
		{
			sprice = ssize - sprice;
			return (sprice + tprice);
		}
	}
	else
		if (tprice < tsize / 2)
			return (sprice - ft_av(sprice - tprice);
	return (sprice + tprice);
}

int	howmanyrotate(t_stack *s, t_stack **t)
{
	t_stack	*ts;
	t_stack	*tt;
	int	tsize;
	int	tprice;
	
	ts = s;
	tt = *t;
	price = 0;
	tsize = ps_lstsize(tt);
	while (tt)
	{
		if (ts->position = tt->position - 1)
			return (price);
		else
			{
				price++;
				tt = tt->next;
			}
	}
	return (price);
}
