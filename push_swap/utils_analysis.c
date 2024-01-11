/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:51:09 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/02 19:10:54 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refresh(t_stack **a, t_stack **b)
{
	if (*a)
		whatindex(a);
	if (*b)
		whatindex(b);
}

void	whatindex(t_stack **s)
{
	int		i;
	int		size;
	t_stack	*curr;

	curr = *s;
	size = ps_lstsize(s);
	i = 0;
	while (curr)
	{
		curr->position = i;
		curr->dte = size - i - 1;
		if (curr->position > (size / 2))
			curr->half = 2;
		else
			curr->half = 1;
		curr = curr->next;
		i++;
	}
}

void	setfinalindex(t_stack **a)
{
	int		i;
	t_stack	*curr;
	t_stack	*temp;

	curr = *a;
	i = 1;
	while (curr)
	{
		i = 1;
		temp = *a;
		while (temp)
		{
			if (temp->number > curr->number)
				i++;
			temp = temp->next;
		}
		curr->f_index = ps_lstsize(a) - i;
		curr = curr->next;
	}
}

int	minnr(t_stack **s)
{
	int		i;
	t_stack	*node;

	node = *s;
	i = (node)->number;
	while (node)
	{
		if ((node)->number < i)
			i = (node)->number;
		node = (node)->next;
	}
	return (i);
}

int	maxnr(t_stack **s)
{
	int		i;
	t_stack	*node;

	node = *s;
	i = (node)->number;
	while (node)
	{
		if ((node)->number > i)
			i = (node)->number;
		node = (node)->next;
	}
	return (i);
}
