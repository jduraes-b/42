/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:03:22 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/24 19:11:38 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cheapest(t_stack *s)
{
	int	i;
	int	temp;

	temp = INT_MAX;
	i = 0;
	while (s)
	{
		if (s->cost < temp)
		{
			temp = s->cost;
			i = s->position;
		}
		s = s->next;
	}
	return (s);
}

void	case_11(t_stack *curr, t_stack **s, t_stack **t)
{
	while (curr->sprice && curr->tprice)
	{
		rr(s, t);
		curr->sprice--;
		curr->tprice--;
	}
	while (curr->sprice)
	{
		ra(s);
		curr->sprice--;
	}
	while (curr->tprice)
	{
		rb(t);
		curr->tprice--;
	}
	pb(s, t);
}

void	case_22(t_stack *curr, t_stack **s, t_stack **t)
{
	curr->sprice = ps_lstsize(s) - curr->sprice;
	curr->tprice = ps_lstsize(t) - curr->tprice;
	while (curr->sprice && curr->tprice)
	{
		rrr(s, t);
		curr->sprice--;
		curr->tprice--;
	}
	while (curr->sprice)
	{
		rra(s);
		curr->sprice--;
	}
	while (curr->tprice)
	{
		rrb(t);
		curr->tprice--;
	}
	pb(s, t);
}
