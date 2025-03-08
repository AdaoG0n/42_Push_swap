/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:21:02 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/25 11:42:41 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_chunks_to_b(t_stack *a, t_stack *b, t_info *info_a)
{
	int	chunk_size;
	int	pushed;
	int	total_size;

	total_size = stack_size(a);
	chunk_size = 19 + (total_size / 71);
	pushed = 0;
	while (stack_size(a) > 3)
	{
		if (a->top->index <= pushed)
		{
			pb(a, b);
			rb(b);
			pushed++;
		}
		else if (a->top->index <= pushed + chunk_size
			&& a->top->value != info_a->max->value)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	t_info	info_a;

	info_a = (t_info){0};
	reset_info_a(stack_a, &info_a);
	push_chunks_to_b(stack_a, stack_b, &info_a);
	sort_three(stack_a);
	push_back(stack_a, stack_b, &info_a);
	while (stack_a->top != info_a.min)
	{
		if (info_a.min_ind <= stack_size(stack_a) / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
