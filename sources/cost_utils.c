/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:21:05 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/21 16:16:16 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_a_cost(t_stack *stack_a, t_lower *lower)
{
	t_node	*current;
	int		i;
	int		closest_bigger;

	current = stack_a->top;
	i = 0;
	closest_bigger = 2147483647;
	while (current)
	{
		if (current->value > lower->value && current->value < closest_bigger)
		{
			closest_bigger = current->value;
			lower->dest = i;
			if (i <= stack_size(stack_a) / 2)
				lower->moves.ra = i;
			else
				lower->moves.rra = stack_size(stack_a) - i;
		}
		current = current->next;
		i++;
	}
}

void	find_b_cost(t_stack *stack_b, t_lower *lower)
{
	int	size;
	int	current_pos;

	size = stack_size(stack_b);
	current_pos = 0;
	if (current_pos <= size / 2)
		lower->moves.rb = current_pos;
	else
		lower->moves.rrb = size - current_pos;
	lower->cost = lower->moves.ra + lower->moves.rb + 
				lower->moves.rra + lower->moves.rrb;
}

void	rotate_stacks(t_stack *stack_a, t_stack *stack_b, t_moves *moves)
{
	while (moves->ra && moves->rb)
	{
		rr(stack_a, stack_b);
		moves->ra--;
		moves->rb--;
	}
	while (moves->rra && moves->rrb)
	{
		rrr(stack_a, stack_b);
		moves->rra--;
		moves->rrb--;
	}
	while (moves->ra--)
		ra(stack_a);
	while (moves->rb--)
		rb(stack_b);
	while (moves->rra--)
		rra(stack_a);
	while (moves->rrb--)
		rrb(stack_b);
}
