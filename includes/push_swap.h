/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:00:17 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 22:16:55 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "limits.h"
# include "stdlib.h"
# include "unistd.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "list.h"

// parsing & validations
t_stack    *parse_arguments(int argc, char **argv);
int	        validate_arguments(t_stack **stack_a, char **numbers, int argc);
void        ft_error(char *message);
t_stack     *create_stack_str(char *str);
t_stack     *create_stack_arr(int argc, char **argv);
t_stack     *safe_exit(t_stack **stack, char **numbers);
int	        is_valid_argument(char *str);
int	        has_duplicate(t_stack *head, int value);
void        assign_indexes(t_stack *stack);

//debug
void print_stack(t_stack *stack, char *name);

// Sorting
void        sort(t_stack **stack_a, t_stack **stack_b);
void	    bitwise_sort(t_stack **stack_a, t_stack **stack_b, int i);
void	    radix_sort(t_stack **stack_a, t_stack **stack_b);
void        sort_three(t_stack **stack_a);
void        sort_five(t_stack **stack_a, t_stack **stack_b);
int find_min(t_stack *stack);
int find_position(t_stack *stack, int value);

// Operations
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void swap(t_stack **stack);
void ss(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_b, t_stack **stack_a);
void pb(t_stack **stack_a, t_stack **stack_b);
void    ra(t_stack **stack_a);
void    rb(t_stack**stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void reverse_rotate(t_stack **stack);
void rrr(t_stack **stack_a, t_stack **stack_b);


#endif
