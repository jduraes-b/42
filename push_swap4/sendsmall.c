/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendsmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:51 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/02 19:14:12 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	goorno(t_stack *st)
{
	int		small;
	int		ammount;
	t_stack	*temp;
	t_stack	*curr;

	ammount = ps_lstsize(&st) / 2;
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

	goorno(*a);
	times = ps_lstsize(a) / 2;
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
}*/

void	sendsmall(t_stack **a, t_stack **b)
{
	t_stack *curr;	
	t_stack	*temp;
	int	i;
	
	curr = *a;
	temp = *a;
	i = ps_lstsize(a) / 2;
	while (curr)
	{
		if (curr->f_index == i)
			break;
		curr = curr->next;
	}
	while (i >= 0)
	{
		temp = *a;
		if (temp->f_index <= curr->f_index)
		{
			pb(a, b);
			i--;
		}
		else
			ra(a);
	}
}
