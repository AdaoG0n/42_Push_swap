/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:29:40 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/12 19:29:41 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void rra(t_stack **stack_a) 
{
    t_stack *last;
    t_stack *second_last;

    last = NULL;
    second_last = NULL;
    if (stack_size(*stack_a) < 2)
        return;
    last = *stack_a;
    while (last->next != NULL) 
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    ft_printf("rra\n");
}

void rrb(t_stack **stack_b) 
{
    t_stack *last;
    t_stack *second_last;
    
    last = NULL;
    second_last= NULL;
    if (stack_size(*stack_b) < 2)
        return;
    last = *stack_b;
    while (last->next != NULL) {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    ft_printf("rrb\n");
}

void rrr(t_stack **stack_a, t_stack **stack_b) 
{
    rra(stack_a);
    rrb(stack_b);
    ft_printf("rrr\n");
}