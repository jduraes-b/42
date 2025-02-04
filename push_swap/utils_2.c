/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:10:53 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/14 18:09:51 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minnr(t_stack **node)
{
	int	i;

	i = (*node)->number;
	while (*node)
	{
		if ((*node)->number < i)
			i = (*node)->number;
		*node = (*node)->next;
	}
	return (i);
}

int	maxnr(t_stack **node)
{
	int	i;

	i = (*node)->number;
	while (*node)
	{
		if ((*node)->number > i)
			i = (*node)->number;
		*node = (*node)->next;
	}
	return (i);
}

int	ps_lstsize(t_stack *st)
{
	int	i;
	
	i = 0;
	if (st == NULL)
		return (i);
	while (st != NULL)
	{
		st = st->next;
		i++;
	}
	return (i);
}
