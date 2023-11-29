/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:16:57 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/15 19:51:39 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stuff(t_stack **a, t_stack **b)
{
	goorno(*a);
	//setfinalindex(*a);
	sendsmall(a, b);
	refresh(a, b);
	setcosts(a, b);
	sort_to_three(a, b);
	sort_three(a);
	refresh(a, b);
	cost_back(a, b);
}

