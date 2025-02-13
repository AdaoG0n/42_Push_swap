/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:29:31 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 22:31:06 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		first = *stack_a;
		second = (*stack_a)->next;
		first->next = second->next;
		second->next = first;
		*stack_a = second;
	}
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

