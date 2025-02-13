/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:45:54 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 22:52:21 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_three(t_stack **stack_a)
{
    if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
        return;
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
    int min;
    int pos;

    while (stack_size(*stack_a) > 3)
    {
        min = find_min(*stack_a);
        pos = find_position(*stack_a, min);
        if (pos <= stack_size(*stack_a) / 2)
        {
            while ((*stack_a)->value != min)
            {
                ra(stack_a);
                // print_stack(*stack_a, "A after ra");
            }
        }
        else
        {
            while ((*stack_a)->value != min)
            {
                rra(stack_a);
                // print_stack(*stack_a, "A after rra");
            }
        }
        pb(stack_a, stack_b);
        // print_stack(*stack_a, "A after pb");
        // print_stack(*stack_b, "B after pb");
    }
    sort_three(stack_a);
    while (*stack_b)
    {
        pa(stack_a, stack_b);
        // print_stack(*stack_a, "A after pa");
    }
}


int find_position(t_stack *stack, int value)
{
    int pos;
    t_stack *temp;

    pos = 0;
    temp = stack;
    while (temp)
    {
        if (temp->value == value)
            return (pos);
        pos++;
        temp = temp->next;
    }
    return (-1);
}

int find_min(t_stack *stack)
{
    t_stack *current;
    int min;
    
    if (!stack)
        return (INT_MAX);
        
    current = stack;
    min = current->value;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    
    return (min);
}

