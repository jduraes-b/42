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

int	minnr(t_stack *node)
{
	int	i;

	i = (node)->number;
	while (node)
	{
		if ((node)->number < i)
			i = (node)->number;
		node = (node)->next;
	}
	return (i);
}

int	maxnr(t_stack *node)
{
	int	i;

	i = (node)->number;
	while (node)
	{
		if ((node)->number > i)
			i = (node)->number;
		node = (node)->next;
	}
	return (i);
}

void	findfindex(t_stack *object, t_stack **s)
{
	t_stack	*curr;
	int	i;

	curr = *s;
	i = 0;
	while (curr)
	{
		if (curr->number > object->number)
			i++;
		curr = curr->next;
	}
	object->f_index = ps_lstsize(*s) - i;
}

void	whereami(t_stack **st)
{
	int		i;
	t_stack	*curr;

	curr = *st;
	i = 0;
	while (curr)
	{
		curr->position = i;
		i++;
		curr = curr->next;
	}
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
