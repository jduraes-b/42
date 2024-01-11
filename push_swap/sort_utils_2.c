/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:46:10 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/10 20:53:52 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_6(t_stack **a, t_stack **b, t_stack *curr)
{
	if (curr->half != 1 && curr->t_half == 1 && \
		targetindex(a, curr->f_index) == 0)
	{
		rrb(b);
		return (1);
	}
	else if (curr->half != 1 && curr->t_half == 0 && targetindex(a,
			curr->f_index) != 0)
	{
		ra(a);
		rrb(b);
		return (1);
	}
	else if (curr->half != 1 && targetindex(a, curr->f_index) == 0)
	{
		rrb(b);
		return (1);
	}
	return (0);
}

int	case_7(t_stack **a, t_stack **b, t_stack *curr)
{
	if (curr->half != 1 && curr->t_half == 1 && targetindex(a,
			curr->f_index) != 0)
	{
		ra(a);
		rrb(b);
		return (1);
	}
	else if (curr->half != 0 && curr->t_half != 0)
	{
		rrr(a, b);
		return (1);
	}
	return (0);
}
