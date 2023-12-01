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
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <string.h>

typedef struct s_stack
{
	int				number;
	int				f_index;
	int				position;
	int				cost;
	int				go;
	int				sprice;
	int				tprice;
	int				half;
	//	struct	s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

int					wrongargs(char **argv);
t_stack				*create_stack(int size, char **content);
void				rotate(t_stack **root);
void				rrotate(t_stack **root);
void				swap(t_stack **root);
void				push(t_stack **source, t_stack **target);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
int					minnr(t_stack *node);
int					maxnr(t_stack *node);
void				goorno(t_stack *st);
void				stuff(t_stack **a, t_stack **b);
int					ps_lstsize(t_stack *st);
void				sendsmall(t_stack **a, t_stack **b);
void				setfinalindex(t_stack **a);
void				findfindex(t_stack *object, t_stack **s);
void				whereami(t_stack **st);
void				refresh(t_stack **a, t_stack **b);
void				setcosts(t_stack **s, t_stack **t);
int					tophcost(t_stack *curr, t_stack **s, t_stack **t);
int					bottomhcost(t_stack *curr, t_stack **s, t_stack **t);
int					howmanyrotate(t_stack *s, t_stack **t);
int					targetfindex(int sfindex, t_stack *t, char list);
int					issorted(t_stack *s);
void				sort_three(t_stack **s);
void	applya(t_stack *curr, t_stack **s, t_stack **t);
void	applyb(t_stack *curr, t_stack **s, t_stack **t);
void	sort_to_three(t_stack **s, t_stack **t);
t_stack	*cheapest(t_stack **s);
void	cost_back(t_stack **a, t_stack **b);
void	sort_back(t_stack **s, t_stack **t);
int	howmanyrotateback(t_stack *s, t_stack **t);
void	case_11a(t_stack *curr, t_stack **s, t_stack **t);
void	case_22a(t_stack *curr, t_stack **s, t_stack **t);
void	case_12a(t_stack *curr, t_stack **s, t_stack **t);
void	case_21a(t_stack *curr, t_stack **s, t_stack **t);
void	case_11b(t_stack *curr, t_stack **s, t_stack **t);
void	case_22b(t_stack *curr, t_stack **s, t_stack **t);
void	case_12b(t_stack *curr, t_stack **s, t_stack **t);
void	case_21b(t_stack *curr, t_stack **s, t_stack **t);


#endif
