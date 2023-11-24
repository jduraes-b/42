/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:30:00 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/09 19:10:26 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	wrongargs(char **argv)
{
	int		i;
	int		j;
	long	nr;

	i = 1;
	j = 0;
	nr = 0;
	while (argv[i])
	{
		j = 0;
		nr = ft_atol(argv[i]);
		if (nr < INT_MIN || nr > INT_MAX)
			return (1);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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
