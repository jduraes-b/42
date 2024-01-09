/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_analysis_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:36:05 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/09 20:19:57 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setbiggest(t_stack **a)
{
	t_stack	*curr;
	int	bignr;
	int	smallnr;

	curr = *a;
	bignr = maxnr(a);
	smallnr = minnr(a);
	while (curr)
	{
		if (curr->number == smallnr)
			curr->biggest = -1;
		if (curr->number == bignr)
			curr->biggest = 1;
		curr = curr->next;
	}
}

int	issorted(t_stack *s)
{
	while (s)
	{
		if (s->next && s->number > s->next->number)
			return (0);
		s = s->next;
	}
	return (1);
}

int	numbercompare(char def, int n1, int n2)
{
	if (def == '+')
	{
		if (n1 > n2)
			return (n1);
		return (n2);
	}
	else
	{
		if (n1 > n2)
			return (n2);
		return (n1);
	}
}

int	targetdte(t_stack **a, int sfi)
{
	int	tindex;
	
	tindex = targetindex(a, sfi);
	tindex = ps_lstsize(a) - tindex - 1;
	return (tindex);
}

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
