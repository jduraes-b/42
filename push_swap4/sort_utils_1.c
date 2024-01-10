/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:53:51 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/10 20:45:35 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_1(t_stack **a, t_stack **b, t_stack *curr)
{
	if (curr->half == 1 && curr->t_half == 2 \
			&& curr->position != 0 && numbercompare('+', curr->position, \
			targetindex(a, curr->f_index)) < numbercompare('+', curr-> \
			dte, targetdte(a, curr->dte) + 1) && \
			numbercompare('+', curr->position, targetindex \
			(a, curr->f_index)) < curr->position + \
			targetdte(a, curr->f_index) + 1)
	{
		rr(a, b);
		return (1);
	}
	else if (curr->half == 1 && curr->t_half == 2 && node->position != 0 &&
			numbercompare('+', curr->dte, \
			targetdte(a, curr->f_index)) + 1 \
			< numbercompare('+', curr->position, targetindex(a, curr-> \
			f_index)) && numbercompare('+', curr->dte, \
			targetdte(a, curr->f_index)) + 1 \
			< curr->position + targetdte(a,	curr->f_index) + 1)
	{
		rrr(a, b);
		return (1);
	}
	return (0);
}

int	case_2(t_stack **a, t_stack **b, t_stack *curr)
{
	if (curr->half == 1 && curr->t_half == 2 && curr->position != 0 && 
			curr->position + targetdte(a, curr->f_index) + 1 < 
			numbercompare('+', curr->dte, targetdte(a, \
			curr->f_index)) + 1 && numbercompare('+', curr->position, \
			targetindex(a, curr->f_index)) > curr->position \
			+ targetdte(a, curr->f_index) + 1)
	{
		rb(a, b);
		return (1);
	}
	else if (curr->half == 2 && curr->t_half == 1 && 
			targetindex(a, curr->f_index) != 0 &&
			curr->dte + targetindex(a, curr->f_index) + 1 <
			numbercompare('+', curr->dte, targetdte(a, curr->f_index)) \
			+ 1 && numbercompare('+', curr->position, targetindex(a,  \
			curr->f_index)) > curr->position + targetdte \
			(a, curr->f_index) + 1)
	{
		ra(a, b);
		return (1);
	}
	return (0);
}

int	case_3(t_stack **a, t_stack **b, t_stack *curr)
{
	if (curr->half == 2 && curr->t_half == 0 && targetindex(a, curr->f_index) != 0 &&
			curr->dte + targetindex(a, curr->f_index) + 1 >
			numbercompare('+', curr->dte, targetdte(a, curr->f_index)) + 1 &&
			numbercompare('+', curr->position, targetindex(a, curr->f_index)) > 
			numbercompare('+', curr->dte, targetdte(a, curr->f_index)) + 1)
	{	
		rrr(a, b);
		return (1);
	}
	else if (curr->half == 2 && curr->t_half == 1 && targetindex(a, curr->f_index) != 0
			&& curr->dte + targietindex(a, curr->dte) + 1 > 
			numbercompare('+', curr->position, targetindex(a, curr->f_index)) \
			&& numbercompare('+', curr->position, targetindex(a, curr->f_index)) <
			numbercompare(curr->dte, targetdte(a, curr->f_index)) + 1)
	{
		rr(a, b);
		return (1);
	}
	return (0);
}

int	case_4(t_stack **a, t_stack **b, t_stack *curr)
{
	if (node->position == 0 && targetindex(a, curr->f_index) == 0)
	{
		pa(a, b);
		return (1);
	}
	else if (curr->half == 1 && node->position == 0 && targetindex(a,
			curr->f_index) != 0)
	{
		ra(a, b);
		return (1);
	}
	else if (curr->half == 1 && node->position != 0
		&& targetindex(a, curr->f_index) == 0)
	{
		rb(a, b);
		return (1);
	}
	return (0);
}

int	case_5(t_stack **a, t_stack **b, t_stack *curr)
{
	if (curr->half == 1 && curr->t_half == 1 && node->position != 0
		&& targetindex(a, curr->f_index) != 0)
	{
		rr(a, b);
		return (1);
	}
	else if (curr->half == 1 && curr->t_half != 0 && curr->position == 0)
	{
		rra(a, b);
		return (1);
	}
	else if (curr->half == 0 && curr->t_half != 0 && curr->position != 0)
	{
		rb(a, b);
		rra(a, b);
		return (1);
	}
	return (0);
}
