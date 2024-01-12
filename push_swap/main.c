/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:54:32 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/12 19:52:40 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_stack	*aroot;
	t_stack	*broot;

	broot = NULL;
	aroot = NULL;
	aroot = create_stack(argc, argv);
	setfinalindex(&aroot);
	refresh(&aroot, &broot);
	setbiggest(&aroot);
	if (ps_lstsize(&aroot) == 2 && !issorted(aroot))
		sa(&aroot);
	if (ps_lstsize(&aroot) == 3)
		sort_three(&aroot);
	if (ps_lstsize(&aroot) > 3 && !issorted(aroot))
		algo(&aroot, &broot);
	ps_lstclear(&aroot);
	ps_lstclear(&broot);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (wrongargs(argv + 1))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
			return (0);
		}
		push_swap(argc, argv);
	}
	return (0);
}
