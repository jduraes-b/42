/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:44:55 by jduraes-          #+#    #+#             */
/*   Updated: 2023/12/04 19:49:13 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	checkrepeat(char **argv)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (1);
			j++;
		}
		i++;	
	}
	return (0);
}

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

int	casebiggest(t_stack **t)
{
	t_stack	*curr;
	int	price;
	
	curr = *t;
	price = 0;
	while (curr)
	{
		if (curr->number == maxnr(t))
			return (price);
		curr = curr->next;
		price++;
	}
	return (-1);
}


