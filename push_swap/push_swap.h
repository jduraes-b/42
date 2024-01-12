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
	int				dte;
	int				half;
	int				t_half;
	int				biggest;
	int				together;
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
int					minnr(t_stack **s);
int					maxnr(t_stack **s);
void				algo(t_stack **a, t_stack **b);
int					ps_lstsize(t_stack **st);
void				sendsmall(t_stack **a, t_stack **b);
void				setfinalindex(t_stack **a);
void				whereami(t_stack **st);
void				refresh(t_stack **a, t_stack **b);
int					issorted(t_stack *s);
void				sort_three(t_stack **s);
void				ps_lstclear(t_stack **lst);
int					checkrepeat(char **argv);
void				setbiggest(t_stack **a);
void				whatindex(t_stack **s);
void				cost(t_stack **a, t_stack **b);
int					targetindex(t_stack **a, int sfi);
int					numbercompare(char def, int n1, int n2);
int					wrongargs(char **argv);
int					checkrepeat(char **argv);
int					targetdte(t_stack **a, int sfi);
t_stack				*cheapest(t_stack **s);
void				sort(t_stack **a, t_stack **b);
void				whatmove(t_stack **a, t_stack **b, t_stack *curr);
int					case_1(t_stack **a, t_stack **b, t_stack *curr);
int					case_2(t_stack **a, t_stack **b, t_stack *curr);
int					case_3(t_stack **a, t_stack **b, t_stack *curr);
int					case_4(t_stack **a, t_stack **b, t_stack *curr);
int					case_5(t_stack **a, t_stack **b, t_stack *curr);
int					case_6(t_stack **a, t_stack **b, t_stack *curr);
int					case_7(t_stack **a, t_stack **b, t_stack *curr);

#endif
