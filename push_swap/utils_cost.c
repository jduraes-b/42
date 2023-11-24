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

int	bottomhcost(int sprice, int tprice, int ssize, int tsize)
{
	if (tprice > tsize / 2)
	{
		if ((tsize - tprice) < (ssize - sprice))
			return (1 + (tsize - tprice));
		else
			return (1 + (ssize - sprice));
	}
	else
		return (1 + (ssize - sprice) + (tprice));
}

int	tophcost(int sprice, int tprice, int tsize)
{
	if (tprice <= tsize / 2)
	{
		if (sprice < tprice)
			return (1 + tprice);
		else
			return (1 + sprice);
	}
	else
		return (1 + sprice + tprice);
}

int	howmanyrotate(t_stack *s, t_stack **t)
{
	t_stack	*ts;
	t_stack	*tt;
	int		tsize;
	int		price;

	ts = s;
	tt = *t;
	price = 0;
	tsize = ps_lstsize(tt);
	while (tt)
	{
		if (targetfindex(ts->f_index, tt) == tt->f_index)
			return (price);
		else
		{
			price++;
			tt = tt->next;
		}
	}
	return (price);
}

int	targetfindex(int sfindex, t_stack *t)
{
	t_stack	*curr;
	int		temp;

	curr = t;
	temp = curr->f_index;
	while (curr)
	{
		if (curr->f_index < sfindex && curr->f_index > temp)
			temp = curr->f_index;
		curr = curr->next;
	}
	return (temp);
}

void	setcosts(t_stack **s, t_stack **t)
{
	int		ssize;
	t_stack	*curr;

	curr = *s;
	ssize = ps_lstsize(*s);
	curr->sprice = 0;
	while (curr)
	{
		refresh(s, t);
		curr->sprice = curr->position;
		curr->tprice = howmanyrotate(curr, t);
		if (curr->sprice < (ps_lstsize(*s) / 2))
		{
			curr->half = 0;
			curr->cost = tophcost(curr->sprice, curr->tprice, ps_lstsize(*t));
		}
		else
		{
			curr->half = 1;
			curr->cost = bottomhcost(curr->sprice, curr->tprice, ps_lstsize(*s),
					ps_lstsize(*t));	
		}			
		curr = curr->next;
	}
}
