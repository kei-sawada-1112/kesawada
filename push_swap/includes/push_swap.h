/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:36:35 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/10 21:14:04 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

enum e_state_ps
{
	A_TO_B,
	B_TO_A,
	SEND_UNDER_HALF,
	SIMPLE_SORT,
	BACK_TO_B,
	END
};

enum e_operation
{
	SA,
	PB,
	RA,
	RRA,
	SB,
	PA,
	SS,
	RB,
	RR,
	RRB,
	RRR,
	INIT
};

typedef struct s_stack
{
	int				value;
	int				is_separator;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_op_list
{
	enum e_operation	op;
	struct s_op_list	*next;
}	t_op_list;

typedef struct s_trans_list
{
	int					count;
	struct s_trans_list	*next;
}	t_trans_list;

typedef struct s_ms
{
	enum e_state_ps		state;
	enum e_operation	op;
	t_op_list			*actual_op;
	t_op_list			*op_list;
	t_trans_list		*trans_list;
	int					limit_count;
	int					count;
	int					min_turn;
}	t_ms;

typedef void	(*t_push_swap_process)(t_stack **, t_stack **, t_ms *);
typedef int		(*t_operation)(t_stack**, t_stack**);

t_stack		*ft_stacknew(int value);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_addstack_front(t_stack **stack, t_stack **new);
void		ft_addstack_back(t_stack **stack, t_stack **new);
int			ft_stacksize(t_stack *a);
int			is_valid_value(t_stack *a);
void		error_and_exit(void);

int			get_median(t_stack *stack, int size);
void		set_index_to_value(t_stack *stack);

void		print_op(int op);
int			execute_and_write(t_stack **a, t_stack **b, int op);

int			swap_a(t_stack **a, t_stack **b);
int			swap_b(t_stack **a, t_stack **b);
int			swap_ab(t_stack **a, t_stack **b);
int			push_a(t_stack **a, t_stack **b);
int			push_b(t_stack **a, t_stack **b);
int			rotate_a(t_stack **a, t_stack **b);
int			rotate_b(t_stack **a, t_stack **b);
int			rotate_ab(t_stack **a, t_stack **b);
int			rotate_rev_a(t_stack **a, t_stack **b);
int			rotate_rev_b(t_stack **a, t_stack **b);
int			rotate_rev_ab(t_stack **a, t_stack **b);

void		init(t_stack **a, t_stack **b, int argc, char **argv);

void		send_a_to_b(t_stack **a, t_stack **b, t_ms *ms);
void		send_b_to_a(t_stack **a, t_stack **b, t_ms *ms);
void		send_under_half(t_stack **a, t_stack **b, t_ms *ms);
void		simple_sort(t_stack **a, t_stack **b, t_ms *ms);
void		back_to_b(t_stack **a, t_stack **b, t_ms *ms);

int			get_current_pos(t_stack *b, int index);

void		sort_under_six(t_stack **a, t_stack **b, t_ms *ms, int count);

void		add_operation(t_op_list **list, int op);
void		delone_operation(t_op_list **list);
void		clear_operation(t_op_list **list);
void		copy_operation(t_ms *ms, t_op_list *list);

void		free_all(t_stack *a, t_stack *b, t_ms *ms);
int			get_min_pos(t_stack *a);
t_ms		*init_ms(void);

void		add_trans_list(t_trans_list **list, int count);
void		delone_trans_list(t_trans_list **list);

int			in_order(t_stack *a);
int			sorted_count(t_stack *a);
int			get_current_pos(t_stack *a, int index);
void		push_b_and_rotate(t_stack **a, t_stack **b, int *i);
void		set_state(t_stack *b, t_ms *ms, int border);

int			is_numstr(char *str);

int			count_descending(t_stack *start, int index);

#endif
