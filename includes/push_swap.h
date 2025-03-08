/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2025/02/17 16:29:19 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/19 16:12:42 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		index;
}	t_stack;

typedef struct s_info
{
	t_node	*min;
	t_node	*max;
	t_node	*mid;
	int		min_ind;
	int		max_ind;
	int		mid_ind;
	int		mid_nb;
	int		count;
}	t_info;

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_moves;

typedef struct s_lower
{
	int		value;
	int		dest;
	int		cost;
	t_moves	moves;
}	t_lower;

// parsing functions
int		valid_args(char *str, t_stack *stack);
int		split_str(char *str, t_stack *stack);
int		is_double(t_stack *stack, int value);
int		parse_args(int argc, char **argv, t_stack *stack_a);

// operations functions
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	rra(t_stack *stack_a);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// sorting functions
void	sort_and_clean(t_stack *stack_a, t_stack *stack_b);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	find_and_move_min(t_stack *stack_a);
int		is_reverse_sorted(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_big(t_stack *stack_a, t_stack *stack_b);
void	push_back(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	reset_info_a(t_stack *stack_a, t_info *info);
int		find_target_position(t_stack *stack_a, int value);

// utils functions
void	ft_error(char *msg);
int		handle_input(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
void	assign_index(t_stack *stack);

// stack functions
t_stack	*create_stack(void);
void	free_stack(t_stack *stack);
void	append(t_stack *stack, int value);
int		stack_size(t_stack *stack);

#endif
