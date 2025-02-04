/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:19:15 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/06 21:40:49 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rotate(t_stack *root)
{
	t_stack	*temp;
	t_stack	*curr;

	temp = root;
	root = root->next;
	curr = root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	curr->next->next = NULL;
}

void	rrotate(t_stack *root)
{
	t_stack	*temp;
	t_stack *curr;

	curr = root;
	while (curr->next->next != NULL)
		curr = curr->next;
	temp = curr->next;
	curr->next = NULL;
	temp->next = root;
}
