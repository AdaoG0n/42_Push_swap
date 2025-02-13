/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:45:54 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 15:52:19 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_three(t_stack **stack_a)
{
    int first = (*stack_a)->value;
    int second = (*stack_a)->next->value;
    int third = (*stack_a)->next->next->value;

    if (first > second && second < third && first < third)
        sa(stack_a);
    else if (first > second && second > third)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (first > second && second < third && first > third)
        ra(stack_a);
    else if (first < second && second > third && first < third)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (first < second && second > third && first > third)
        rra(stack_a);
}

void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    while (stack_size(*stack_a) > 3)
    {
        int min = find_min(*stack_a);
        int pos = 0;
        t_stack *temp = *stack_a;
        while (temp && temp->value != min)
        {
            pos++;
            temp = temp->next;
        }
        if (pos <= stack_size(*stack_a) / 2)
        {
            while ((*stack_a)->value != min)
                ra(stack_a);
        }
        else
        {
            while ((*stack_a)->value != min)
                rra(stack_a);
        }

        pb(stack_a, stack_b);
    }
    sort_three(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b);
}


int find_min(t_stack *stack)
{
    int min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return min;
}
