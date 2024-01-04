/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:31:02 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/03 20:31:59 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **s)
{
	if (maxnr(s) == (*s)->next->next->number && !issorted(*s))
		sa(s);
	else if (maxnr(s) == (*s)->number)
	{
		ra(s);
		if (!issorted(*s))
			sa(s);
	}
	else
	{
		if (maxnr(s) == (*s)->next->number)
			rra(s);
		if (!issorted(*s))
			sa(s);
	}
}

