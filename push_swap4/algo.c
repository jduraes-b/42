/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:23:00 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/02 19:15:04 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_stack **a, t_stack **b)
{
	/*(void) b;
	t_stack *curr;
	
	curr = *a;*/
	setbiggest(a);
	/*while (curr)
	{
		ft_printf("%d %d \n", curr->number, curr->f_index);
		curr = curr->next;
	}*/
	sendsmall(a, b);
	while (ps_lstsize(a) > 3)
		pb(a, b);
	refresh(a, b);
	sort_three(a);
	refresh(a, b);
	cost(a, b);
}
