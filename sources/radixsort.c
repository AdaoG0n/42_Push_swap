/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:47:26 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 11:23:40 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bitwise_sort(t_stack **stack_a, t_stack **stack_b, int i)
{
	int			j;
	int			size;
	t_stack	*temp;

	size = stack_size(*stack_a);
	j = 0;
	while (j++ < size)
	{
		temp = *stack_a;
		if ((temp->index >> i) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (is_sorted(*stack_a) != 1 && i < 32)
	{
		bitwise_sort(stack_a, stack_b, i);
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
	free_stack(stack_b);
}

int	process_input(int argc, char **argv, t_stack **stack_a, int start_index)
{
	int		i;
	int		j;
	long	num;

	j = -1;
	i = start_index - 1;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigitplussign(argv[i][j]))
				return (1);
		num = ft_atol(argv[i]);
		if (has_duplicate(*stack_a, num))
			return (1);
		if (num < -2147483648 || num > 2147483647)
			return (1);
		push(stack_a, (int)num);
	}
	return (0);
}
int	is_sorted(t_stack *head)
{
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}