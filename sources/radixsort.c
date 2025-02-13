/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:47:26 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 23:08:05 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void assign_indexes(t_stack *stack)
{
    t_stack *current;
    t_stack *temp;
    int min;
    int index;

    index = 0;
    while (index < stack_size(stack))
    {
        min = INT_MAX;
        current = stack;
        while (current)
        {
            if (current->value < min && current->index == -1)
                min = current->value;
            current = current->next;
        }
        temp = stack;
        while (temp)
        {
            if (temp->value == min && temp->index == -1)
            {
                temp->index = index;
                break;
            }
            temp = temp->next;
        }
        index++;
    }
}

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
    int i = 0;
    t_stack *temp;

    // Encontrar o número máximo de bits necessários
    temp = *stack_a;
    while (temp)
    {
        int bits = 0;
        int index = temp->index;
        while (index >> bits)
            bits++;
        if (bits > max_bits)
            max_bits = bits;
        temp = temp->next;
    }
    while (i < max_bits)
    {
        bitwise_sort(stack_a, stack_b, i);
        i++;
    }
}

//debug apenas
void print_stack(t_stack *stack, char *name)
{
    t_stack *temp;
    int position;
    (void)stack;
    (void)name;
    

    if (!stack)
    {
        ft_printf("\033[1;31mStack %s is empty\033[0m\n", name);
        return;
    }

    ft_printf("\n\033[1;34mStack %s:\033[0m\n", name);
    ft_printf("\033[1;33m-------------------\033[0m\n");
    
    position = 0;
    temp = stack;
    while (temp)
    {
        ft_printf("\033[1;32mPosition %d: %d\033[0m\n", position, temp->value);
        temp = temp->next;
        position++;
    }
    ft_printf("\033[1;33m-------------------\033[0m\n");
}






