/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:29:31 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/12 19:29:32 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sa(t_stack **stack_a)
{
    t_stack *temp;

    temp = NULL;
    if (stack_size(*stack_a) < 2)
        return;
    temp = (*stack_a)->next;
    (*stack_a)->next = temp->next;
    temp->next = *stack_a;
    *stack_a = temp;
    ft_printf("sa/n");
}
void    sb(t_stack **stack_b)
{
    t_stack *temp;

    temp = NULL;
    if (stack_size(*stack_b) < 2)
        return;
    temp = (*stack_b)->next;
    (*stack_b)->next = temp->next;
    temp->next = *stack_b;
    *stack_b = temp;
    ft_printf("sb\n");
}
void    ss(t_stack **stack_a, t_stack **stack_b) 
{
    sa(stack_a);
    sb(stack_b);
    ft_printf("ss\n");
}
