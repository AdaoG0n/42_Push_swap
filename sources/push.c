/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:11:59 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/18 15:56:58 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b->top == NULL)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	temp->next = stack_a->top;
	stack_a->top = temp;
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_a->top == NULL)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	temp->next = stack_b->top;
	stack_b->top = temp;
	ft_printf("pb\n");
}
