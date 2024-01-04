/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_analysis_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:36:05 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/04 21:02:12 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setbiggest(t_stack **a)
{
	t_stack	*curr;
	int	bignr;
	int	smallnr;

	curr = *a;
	bignr = maxnr(a);
	smallnr = minnr(a);
	while (curr)
	{
		if (curr->number == smallnr)
			curr->biggest = -1;
		if (curr->number == bignr)
			curr->biggest = 1;
		curr = curr->next;
	}
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

int	numbercompare(int n1, int n2, char def)
{
	if (def == '+')
	{
		if (n1 > n2)
			return (n1);
		return (n2);
	}
	if (def == '-')
	{
		if (n1 > n2)
			return (n2);
		return (n1);
	}
}
