/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:19:06 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/24 17:46:44 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	goorno(t_stack *st)
{
	int		small;
	int		ammount;
	t_stack	*temp;
	t_stack	*curr;

	ammount = ps_lstsize(st) / 2;
	small = (st)->number;
	temp = st;
	while (ammount)
	{
		curr = st;
		small = INT_MAX;
		while (curr)
		{
			if (curr->number < small && curr->go != 1)
			{
				small = (curr)->number;
				temp = curr;
			}
			curr = curr->next;
		}
		temp->go = 1;
		ammount--;
	}
}

void	sendsmall(t_stack **a, t_stack **b)
{
	int		times;

	times = ps_lstsize(*a) / 2;
	while (*a && times)
	{
		if ((*a)->go == 1)
		{
			pb(a, b);
			times--;
		}
		else
			ra(a);
	}
}

void	setfinalindex(t_stack **a)
{
	t_stack	*curr;

	curr = *a;
	while (curr)
	{
		findfindex(curr, a);
		curr = curr->next;
	}
}

void	refresh(t_stack **a, t_stack **b)
{
	whereami(a);
	whereami(b);
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
