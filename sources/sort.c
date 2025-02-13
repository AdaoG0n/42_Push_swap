/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:08:48 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 17:58:51 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort(t_stack **stack_a, t_stack **stack_b) 
{
    if (!stack_a || !*stack_a || is_sorted(*stack_a))
        return;

    int size = stack_size(*stack_a);

    if (size == 2)
        sa(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    else if (size <= 5)
        sort_five(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}

int is_sorted(t_stack *head)
{
    if (!head)
        return (1);
    while (head && head->next)
    {
        if (head->value > head->next->value)
            return (0);
        head = head->next;
    }
    return (1);
}