/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:29:40 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 22:30:02 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*prev;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	prev = NULL;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	temp->next = *stack_a;
	*stack_a = temp;
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

void reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *second_last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    last = *stack;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

void rrr(t_stack **stack_a, t_stack **stack_b) 
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_printf("rrr\n");
}
