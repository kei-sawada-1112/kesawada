/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:36:35 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/23 12:43:12 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

#define TABLE_SIZE 421

typedef struct s_node {
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct {
	t_node	*entries[TABLE_SIZE];
}	t_hashtable;

typedef struct	s_stack
{
	int				value;
	int				is_separator;
	int				current_stack;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct	s_info
{
	t_stack		*stack;
	t_hashtable	*table;
	int			rotate_count;
	int			push_count;
}	t_info;

void		init_stack(t_stack **stack, char **argv);
t_stack		*ft_stacknew(int value);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_addstack_front(t_stack **stack, t_stack *new);
void		ft_addstack_back(t_stack **stack, t_stack *new);
void		ft_stackmove(t_stack *to, t_stack *from);
int			ft_stackrot(t_info *a, t_info *b);
int			ft_stackrot_rev(t_info *a, t_info *b);

t_hashtable	*init_hashtable(void);
void		add_to_hashtable(t_hashtable *table, int value, int i);

int 		get_median(t_stack *stack, int size);

int			swap_top(t_info *a, t_info *b);
int 		push(t_info *to, t_info *from);
int			rotate(t_info *a, t_info *b);
int			rotate_rev(t_info *a, t_info *b);

int			is_numstr(char *str);

#endif
