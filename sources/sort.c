/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:33:27 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/21 15:19:16 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_index(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	if (stack == NULL || stack->top == NULL)
		return ;
	current = stack->top;
	while (current)
	{
		compare = stack->top;
		index = 0;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	is_reverse_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return (0);
	current = stack->top;
	while (current->next)
	{
		if (current->value < current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_and_clean(t_stack *stack_a, t_stack *stack_b)
{
	int		size;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	size = stack_size(stack_a);
	assign_index(stack_a);
	if (is_sorted(stack_a))
		return ;
	else
	{
		if (size == 2)
			sort_two(stack_a);
		else if (size == 3)
			sort_three(stack_a);
		else if (size == 4)
			sort_four(stack_a, stack_b);
		else if (size == 5)
			sort_five(stack_a, stack_b);
		else
			sort_big(stack_a, stack_b);
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
