/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:19:06 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/15 19:12:59 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	goorno(t_stack *st)
{
	int	small;
	int	ammount;
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
	t_stack	*temp;
	int	times;
	
	times = ps_lstsize(*a) / 2;
	temp = *a;
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

void	setfinalindex(t_stack *a)
{
	int	small;
	int	i;
	t_stack	*temp;
	t_stack	*curr;

	temp = a;
	i = 1;
	while (i <= ps_lstsize(a))
	{
		curr = a;
		small = INT_MAX;
		while (curr)
		{
			if (curr->number < small && curr->f_index == 0)
			{
				small = curr->number;
				temp = curr;
			}
			curr = curr->next;
		}
		temp->f_index = i++;
	}
}
