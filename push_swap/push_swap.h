/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:59:31 by jduraes-          #+#    #+#             */
/*   Updated: 2023/11/14 19:49:53 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <string.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

typedef struct	s_stack
{
	int	number;
	int	f_index;
	int	position;
	int	cost;
	int	go;
//	struct	s_stack	*prev;
	struct	s_stack	*next;
}	t_stack;

int	wrongargs(char **argv);
t_stack	*create_stack(int size, char** content);
void	rotate(t_stack **root);
void	rrotate(t_stack **root);
void	swap(t_stack **root);
void	push(t_stack **source, t_stack **target);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	goorno(t_stack *st);
void	stuff(t_stack **a, t_stack **b);
int	ps_lstsize(t_stack *st);
void    sendsmall(t_stack **a, t_stack **b);
void    setfinalindex(t_stack *a);
void	whereami(t_stack **st);
void	refresh(t_stack **a, t_stack **b);
void	setcosts(t_stack **s, t_stack **t);
int	getfinalcost(int sprice, int tprice, int ssize, int tsize);
int	howmanyrotate(t_stack *s, t_stack **t);

#endif
