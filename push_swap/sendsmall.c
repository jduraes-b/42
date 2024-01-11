/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendsmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:51 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/11 21:13:35 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sendsmall(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	t_stack	*temp;
	int		i;

	curr = *a;
	temp = *a;
	i = ps_lstsize(a) / 2;
	while (curr)
	{
		if (curr->f_index == i)
			break ;
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
