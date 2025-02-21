/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:17:50 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/19 16:02:58 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*first;
	t_node	*last;

	if (stack_a->top == NULL || stack_a->top->next == NULL)
		return ;
	first = stack_a->top;
	stack_a->top = first->next;
	last = stack_a->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*last;

	if (stack_b->top == NULL || stack_b->top->next == NULL)
		return ;
	first = stack_b->top;
	stack_b->top = first->next;
	last = stack_b->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}
