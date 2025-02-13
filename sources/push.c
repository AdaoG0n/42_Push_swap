/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:29:34 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 22:25:56 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void pa(t_stack **stack_a, t_stack **stack_b)
// {
//     t_stack *temp;

//     if (!*stack_b)
//         return;
//     temp = *stack_b;
//     *stack_b = (*stack_b)->next;
//     temp->next = *stack_a;
//     *stack_a = temp;
//     ft_printf("pa\n");
// }

// void pb(t_stack **stack_a, t_stack **stack_b)
// {
//     t_stack *temp;

//     if (!*stack_a)
//         return;
//     temp = *stack_a;
//     *stack_a = (*stack_a)->next;
//     temp->next = *stack_b;
//     *stack_b = temp;
//     ft_printf("pb\n");
// }

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b != NULL)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
	}
	ft_printf("pb\n");
}


