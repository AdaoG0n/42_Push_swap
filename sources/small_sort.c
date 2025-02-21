/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:41:47 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/18 15:57:50 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a);
	else
		return ;
}

void	sort_three(t_stack *stack_a)
{
	int		first;
	int		second;
	int		third;

	first = stack_a->top->value;
	second = stack_a->top->next->value;
	third = stack_a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third && first > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	find_and_move_min(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	find_and_move_min(stack_a);
	pb(stack_a, stack_b);
	find_and_move_min(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	find_and_move_min(t_stack *stack_a)
{
	int		min;
	int		rracheck;
	t_node	*temp;

	if (stack_a == NULL)
		return ;
	rracheck = 0;
	min = stack_a->top->value;
	temp = stack_a->top;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	if (is_reverse_sorted(stack_a))
	{
		rracheck = 1;
		rra(stack_a);
	}
	while (stack_a->top && stack_a->top->value != min && rracheck == 0)
		ra(stack_a);
}
