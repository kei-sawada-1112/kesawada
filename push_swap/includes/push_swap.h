/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:36:35 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/25 13:26:16 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

enum e_state_ps
{
	UNDER_SIX,
	A_TO_B,
	QUICK_SORT_B,
	SORTED_TO_BOTTOM,
	QUICK_SORT_A,
	END
};

enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	INIT
};

typedef struct	s_stack
{
	int				value;
	int				is_separator;
	int				index;
	int				pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_op_list
{
	enum e_operation	op;
	struct s_op_list	*next;
}	t_op_list;

typedef struct	s_ms
{
	enum e_state_ps		state;
	enum e_operation	op;
	t_op_list			*actual_op;
	t_op_list			*op_list;
	int					limit_count;
	int					count;
	int					push_count;
}	t_ms;

typedef void	(*t_push_swap_process)(t_stack **, t_stack **, t_ms *, int);
typedef int		(*t_operation)(t_stack**, t_stack**, t_ms*);

t_stack		*ft_stacknew(int value, int pos);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_addstack_front(t_stack **stack, t_stack **new);
void		ft_addstack_back(t_stack **stack, t_stack **new);

int 		get_median(t_stack *stack, int size);
void		set_index_to_value(t_stack *stack, int *array, int argc);

int		swap_a(t_stack **a, t_stack **b, t_ms *ms);
int		swap_b(t_stack **a, t_stack **b, t_ms *ms);
int 	swap_ab(t_stack **a, t_stack **b, t_ms *ms);
int 	push_a(t_stack **a, t_stack **b, t_ms *ms);
int 	push_b(t_stack **a, t_stack **b, t_ms *ms);
int		rotate_a(t_stack **a, t_stack **b, t_ms *ms);
int		rotate_b(t_stack **a, t_stack **b, t_ms *ms);
int		rotate_ab(t_stack **a, t_stack **b, t_ms *ms);
int		rotate_rev_a(t_stack **a, t_stack **b, t_ms *ms);
int		rotate_rev_b(t_stack **a, t_stack **b, t_ms *ms);
int		rotate_rev_ab(t_stack **a, t_stack **b, t_ms *ms);

void	append_stack(t_stack **stack, int num, int pos);

void	init(t_stack **a, t_stack **b, int argc, char **argv);

void	send_a_to_b(t_stack **a, t_stack **b, t_ms *ms, int size);
void	sort_under_six(t_stack **a, t_stack **b, t_ms *ms, int count);

void	add_operation(t_op_list **list, int op);
void	delone_operation(t_op_list **list);
void	clear_operation(t_op_list **list);
void	copy_operation(t_ms *ms, t_op_list *list);

int		is_numstr(char *str);

#endif
