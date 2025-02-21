/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:13:33 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/19 16:03:58 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_size(stack_a) < 2)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	temp->next = stack_a->top->next;
	stack_a->top->next = temp;
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_size(stack_b) < 2)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	temp->next = stack_b->top->next;
	stack_b->top->next = temp;
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
