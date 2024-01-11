/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:12:16 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/11 21:06:59 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost(t_stack **a, t_stack **b)
{
	t_stack	*curr;

	curr = *b;
	while (curr)
	{
		curr->cost = numbercompare('-', curr->position + targetdte(a, \
			curr->f_index) + 2, numbercompare('-', curr->dte \
			+ targetindex(a, curr->f_index) + 2, numbercompare('-', \
			numbercompare('+', curr->position, targetindex(a, \
			curr->f_index)) + 1, numbercompare('+', \
			curr->dte + 1, targetdte(a, curr->f_index) + 1) + 1)));
		if (targetindex(a, curr->f_index) <= targetdte(a, curr->f_index))
			curr->t_half = 1;
		else
			curr->t_half = 2;
		curr = curr->next;
	}
}

int	targetindex(t_stack **a, int sfi)
{
	t_stack	*curr;
	int		tindex;
	int		tfindex;

	tindex = -1;
	tfindex = -1;
	curr = *a;
	while (curr)
	{
		if ((curr->f_index > sfi && curr->f_index < tfindex)
			|| (tindex == -1 && curr->f_index > sfi))
		{
			tfindex = curr->f_index;
			tindex = curr->position;
		}
		curr = curr->next;
	}
	if (tindex == -1)
	{
		curr = *a;
		while (curr->number != minnr(a))
			curr = curr->next;
		tindex = curr->position;
	}
	return (tindex);
}

int	targetdte(t_stack **a, int sfi)
{
	int	tindex;

	tindex = targetindex(a, sfi);
	tindex = ps_lstsize(a) - tindex - 1;
	return (tindex);
}
