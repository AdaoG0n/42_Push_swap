/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:29:37 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 22:28:24 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*first;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	first = *stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	*stack_a = first->next;
	first->next = NULL;
	temp->next = first;
	ft_printf("ra\n");
}

void    rb(t_stack**stack_b)
{
    t_stack *first;
    t_stack *last;

    first = NULL;
    last = NULL;
    if (stack_size(*stack_b) < 2)
        return;
    first = *stack_b;
    last = *stack_b;
    while (last->next != NULL)
        last = last->next;
    *stack_b = first->next;
    first->next = NULL;
    last->next = first;
    ft_printf("rb\n");
}
void    rr(t_stack **stack_a, t_stack **stack_b) 
{
    ra(stack_a);
    rb(stack_b);
    ft_printf("rr\n");
}