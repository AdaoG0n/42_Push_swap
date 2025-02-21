/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:12:46 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/17 21:17:35 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_double(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	valid_args(char *str, t_stack *stack)
{
	int		i;
	long	num;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigitplussign(str[i]))
			return (ft_error("Error"), 0);
		i++;
	}
	num = ft_atol(str);
	if (num < -2147483648 || num > 2147483647)
		return (ft_error("Error"), 0);
	if (is_double(stack, (int)num))
		return (ft_error("Error"), 0);
	return (1);
}
