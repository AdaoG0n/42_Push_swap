/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:00:17 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 11:22:23 by adamarqu         ###   ########.fr       */
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

// Sorting
void        sort(t_stack **stack_a, t_stack **stack_b);
int         is_sorted(t_stack *head);
void	    bitwise_sort(t_stack **stack_a, t_stack **stack_b, int i);
void	    radix_sort(t_stack **stack_a, t_stack **stack_b);

// Process
int	        process_input(int argc, char **argv, t_stack **stack_a, int start_index);

// Operations
void        sa(t_stack **head);
void        sb(t_stack **head);
void        ss(t_stack **stack_a, t_stack **stack_b);
void        pa(t_stack **stack_a, t_stack **stack_b);
void        pb(t_stack **stack_a, t_stack **stack_b);
void        ra(t_stack **head);
void        rb(t_stack **head);
void        rr(t_stack **stack_a, t_stack **stack_b);
void        rra(t_stack **head);
void        rrb(t_stack **head);
void        rrr(t_stack **stack_a, t_stack **stack_b);


#endif
