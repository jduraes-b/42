/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:07:24 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/06 19:31:46 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char** argv)
{
	t_stack	*root;
	//t_stack	*curr;

	root = NULL;
	root = create_stack(argc, argv);
	/*curr = root;
	while(curr != NULL)
	{
		ft_printf("%d\n", curr->number);
		curr= curr->next;
	}*/
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
