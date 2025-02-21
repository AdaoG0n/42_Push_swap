/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2025/02/17 22:16:38 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/19 16:01:40 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*temp;
	t_node	*last;

	if (stack_size(stack_a) < 2)
		return ;
	temp = stack_a->top;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = stack_a->top;
	stack_a->top = last;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	t_node	*temp;
	t_node	*last;

	if (stack_size(stack_b) < 2)
		return ;
	temp = stack_b->top;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = stack_b->top;
	stack_b->top = last;
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}
