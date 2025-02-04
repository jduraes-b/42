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

void	setcosts(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	t_stack *temp;
	int	index;
	int	size;

	curr = *a;
	size = ps_lstsize(a);
	index = 1;
	while (curr)
	{
		curr->cost = findcost(curr, *b, index, size);
	}
}

int	findcost(t_stack *curr, t_stack *b, int index, int size)
{
	int	price;
	int	tprice;
	t_stack	*temp;

	temp = b;
	if (index > size / 2)
		price = size - index;
	else
		price = index;
	while (temp)
	{
		if (curr->f_index 
	}
}
