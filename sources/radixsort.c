/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:47:26 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 15:42:40 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void assign_indexes(t_stack *stack)
{
    t_stack *current;
    t_stack *min;
    int index = 0;

    while (index < stack_size(stack))
    {
        current = stack;
        min = NULL;
        while (current)
        {
            if ((min == NULL || current->value < min->value) && current->index == -1)
                min = current;
            current = current->next;
        }
        if (min)
            min->index = index++;
    }
}

#include "../includes/push_swap.h"

void bitwise_sort(t_stack **stack_a, t_stack **stack_b, int i)
{
    int size = stack_size(*stack_a);
    int j = 0;

    while (j++ < size)
    {
        if (((*stack_a)->index >> i) & 1)
            ra(stack_a);
        else
            pb(stack_a, stack_b);
    }
    while (*stack_b)
        pa(stack_a, stack_b);
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int max_bits = 0;
    int max = stack_size(*stack_a) - 1;

    while ((max >> max_bits) != 0)
        max_bits++;

    for (int i = 0; i < max_bits; i++)
        bitwise_sort(stack_a, stack_b, i);
}


