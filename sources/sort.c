/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:08:48 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 11:09:23 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort(t_stack **stack_a, t_stack **stack_b) 
{
    if (!stack_a || !*stack_a)
        return;
    if (is_sorted(*stack_a))
        return;
    if (stack_size(*stack_a) == 2) {
        sa(stack_a);
        return;
    }
    if (stack_size(*stack_a) == 3)
    {
        return;
    }
    radix_sort(stack_a, stack_b);
}