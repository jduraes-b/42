/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:07:24 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/13 18:30:35 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char** argv)
{
	t_stack	*aroot;
	t_stack	*curr;
	t_stack	*broot;

	broot = NULL;
	
	aroot = NULL;
	aroot = create_stack(argc, argv);
	//sa(&aroot);
	pb(&aroot, &broot);
	pb(&aroot, &broot);
	rr(&aroot, &broot);
	ss(&aroot, &broot);
	//sb(&broot);
	curr = aroot;
	while(curr != NULL)
	{
		ft_printf("%d\n", curr->number);
		curr= curr->next;
	}
	write(1, "\n", 1);
	curr = broot;
	while(curr != NULL)
	{
		ft_printf("%d\n", curr->number);
		curr= curr->next;
	}
}

int	main(int argc, char** argv)
{
	if (argc > 1)
	{
		if (wrongargs(argv))
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
