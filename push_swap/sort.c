/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:06:07 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/24 18:57:07 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **s)
{
	if (minnr(*s) == (*s)->number)
	{
		ra(s);
		sa(s);
	}
	else if (maxnr(*s) == (*s)->number)
	{
		ra(s);
		if (!issorted(*s))
			sa(s);
	}
	else
	{
		if (maxnr(*s) == (*s)->next->number)
			rra(s);
		else
			sa(s);
	}
}

void	sort_to_three(t_stack **s, t_stack **t)
{
	while (ps_lstsize(*s) > 3)
	{
		setcosts(s, t);
		apply(s, t);
	}
}

void	apply(t_stack **s, t_stack **t);
