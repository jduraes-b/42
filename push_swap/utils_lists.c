/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:24:37 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/02 19:09:07 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	newnr(t_stack *curr, char **content, int i)
{
	t_stack	*new;

	new = calloc(1, sizeof(t_stack));
	if (!new)
		return ;
	new->number = ft_atoi(content[i]);
	new->next = NULL;
	curr->next = new;
}

t_stack	*create_stack(int size, char **content)
{
	t_stack	*root;
	t_stack	*curr;
	int		i;

	i = 1;
	root = ft_calloc(1, sizeof(t_stack));
	if (root == NULL)
		return (NULL);
	root->number = ft_atoi(content[i++]);
	root->next = NULL;
	curr = root;
	while (i < size)
	{
		newnr(curr, content, i);
		curr = curr->next;
		i++;
	}
	return (root);
}

int	ps_lstsize(t_stack **st)
{
	int		i;
	t_stack	*curr;

	curr = *st;
	i = 0;
	if (curr == NULL)
		return (i);
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

void	ps_lstclear(t_stack **lst)
{
	t_stack	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			free(*lst);
			(*lst) = temp;
		}
	}
}
