/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:42:13 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/20 21:28:41 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	current = stack->top;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(stack);
}

void	append(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (stack->top == NULL)
	{
		stack->top = new_node;
	}
	else
	{
		current = stack->top;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

int	stack_size(t_stack *stack)
{
	t_node	*current;
	int		size;

	size = 0;
	current = stack->top;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
