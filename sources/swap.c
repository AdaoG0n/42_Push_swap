/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:29:31 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 15:18:24 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sa(t_stack **stack_a)
{
    t_stack *temp;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    temp = (*stack_a)->next;
    (*stack_a)->next = temp->next;
    temp->next = *stack_a;
    *stack_a = temp;
    ft_printf("sa\n");
}

void    sb(t_stack **stack_b)
{
    t_stack *temp;

    temp = NULL;
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    temp = (*stack_b)->next;
    (*stack_b)->next = temp->next;
    temp->next = *stack_b;
    *stack_b = temp;
    ft_printf("sb\n");
}
void swap(t_stack **stack)
{
    t_stack *temp;

    if (!stack || !*stack || !(*stack)->next)
        return;
    temp = (*stack)->next;
    (*stack)->next = temp->next;
    temp->next = *stack;
    *stack = temp;
}

void ss(t_stack **stack_a, t_stack **stack_b) 
{
    swap(stack_a);
    swap(stack_b);
    ft_printf("ss\n");
}

