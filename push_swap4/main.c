/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:54:32 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/02 18:22:50 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_stack	*aroot;
	t_stack	*curr;
	t_stack	*broot;

	broot = NULL;
	aroot = NULL;
	aroot = create_stack(argc, argv);
	setfinalindex(&aroot);
	refresh(&aroot, &broot);
	if (ps_lstsize(&aroot) == 2 && !issorted(aroot))
		sa(&aroot);
	if (ps_lstsize(&aroot) == 3)
		sort_three(&aroot);
	//if (ps_lstsize(aroot) == 5)
	//	sort_five(&aroot, &broot);
	if (ps_lstsize(&aroot) > 3 && !issorted(aroot))
		algo(&aroot, &broot);
	curr = aroot;
	while (curr != NULL)
	{
		ft_printf("%d\n", curr->number);
		curr = curr->next;
	}
	write(1, "\n", 1);
	curr = broot;
	while (curr != NULL)
	{
		ft_printf("%d, cost: %d, target: %d\n", curr->number, curr->cost, targetindex(&aroot, curr->f_index));
		curr = curr->next;
	}
	ps_lstclear(&aroot);
	ps_lstclear(&broot);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (wrongargs(argv + 1))
		{
			ft_printf("wrong arguments");
			return (1);
		}
		push_swap(argc, argv);
	}
	else
		ft_printf("Wrong number of arguments\n");
	return (0);
}
