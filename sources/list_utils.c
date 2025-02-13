/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:00:14 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 10:46:09 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_node(int value)
{
	t_stack *new_node;
	
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	push(t_stack **head, int new_data)
{
	t_stack *new_node;
	
	new_node = create_node(new_data);
	if (new_node == NULL)
		ft_error("Error");
	new_node->next = *head;
	*head = new_node;
}

void	free_stack(t_stack **head)
{
	t_stack *current;
	t_stack *next;

	current = *head;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

int	stack_size(t_stack *head)
{
	int	count;
	t_stack *current;
	
	count = 0;
	current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

