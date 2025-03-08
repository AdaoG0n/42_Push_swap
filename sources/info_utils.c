/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:21:28 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/25 11:46:42 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*get_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min;

	current = stack->top;
	min = current;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

static t_node	*get_max(t_stack *stack)
{
	t_node	*current;
	t_node	*max;

	current = stack->top;
	max = current;
	while (current)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

void	reset_info_a(t_stack *stack_a, t_info *info)
{
	t_node	*current;
	int		size;
	int		i;

	if (!stack_a || !info)
		return ;
	info->min = get_min(stack_a);
	info->max = get_max(stack_a);
	size = stack_size(stack_a);
	info->mid_ind = size / 2;
	current = stack_a->top;
	i = 0;
	while (current)
	{
		if (current == info->min)
			info->min_ind = i;
		if (current == info->max)
			info->max_ind = i;
		current = current->next;
		i++;
	}
}

static void	rotate_and_push(t_stack *stack_a, t_stack *stack_b, t_info *info, int target_pos)
{
    int	size_a;

    size_a = stack_size(stack_a);
    if (target_pos <= size_a / 2)
    {
        while (target_pos > 0)
        {
            ra(stack_a);
            target_pos--;
        }
    }
    else
    {
        while (target_pos < size_a)
        {
            rra(stack_a);
            target_pos++;
        }
    }
    pa(stack_a, stack_b);
    reset_info_a(stack_a, info);
}

void	push_back(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
    int	target_pos;

    while (stack_b->top)
    {
        target_pos = find_target_position(stack_a, stack_b->top->value);
        rotate_and_push(stack_a, stack_b, info, target_pos);
    }
    while (stack_a->top->value != info->min->value)
        ra(stack_a);
}

int	find_target_position(t_stack *stack_a, int value)
{
	t_node	*current;
	int		target_pos;
	int		closest_bigger;
	int		pos;

	current = stack_a->top;
	closest_bigger = 2147483647;
	target_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value > value && current->value < closest_bigger)
		{
			closest_bigger = current->value;
			target_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (target_pos);
}
