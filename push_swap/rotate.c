/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:19:15 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/10 19:02:11 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **root)
{
	t_stack	*temp;
	t_stack	*curr;

	temp = *root;
	*root = (*root)->next;
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	curr->next->next = NULL;
}

void	rrotate(t_stack **root)
{
	t_stack	*temp;
	t_stack *curr;

	curr = *root;
	temp = *root;
	while (curr->next->next != NULL)
		curr = curr->next;
	*root = curr->next;
	(*root)->next = temp;
	curr->next = NULL;
}
