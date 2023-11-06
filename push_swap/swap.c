/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:02:05 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/06 21:19:06 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *root)
{
	t_stack	*temp;

	temp = *root;
	temp->next = root->next->next;
	root = root->next;
	root->next = *temp;
}
