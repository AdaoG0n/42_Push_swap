/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:29:51 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 17:32:23 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
t_stack *safe_exit(t_stack **stack, char **numbers)
{
	int	i;

	i = 0;
    if (stack && *stack) 
	{
        free_stack(stack);
        *stack = NULL;
    }
    if (numbers)
    {
        while (numbers[i])
        {
            free(numbers[i]);
            i++;
        }
        free(numbers);
    }
    return (NULL);
}
int	is_valid_argument(char *str)
{
	int	i;
	int	num;

	i = 0;
	if (!str || str[0] == '\0')
		return(0);
	if(str[0] == '-' || str[0] == '+')
		i++;
	while(str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return(0);
		i++;
	}
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return(1);
}
int has_duplicate(t_stack *stack, int value)
{
    t_stack *current;
    int count = 0;

    current = stack;
    while (current)
    {
        if (current->value == value)
            count++;
        if (count > 1)
            return (1);
        current = current->next;
    }
    return (0);
}

int	validate_arguments(t_stack **stack_a, char **numbers, int argc)
{
	int		i;
	long	num;

	i = 0;
	while (i < argc)
	{
		if (!is_valid_argument(numbers[i]))
			return (safe_exit(stack_a, numbers), ft_error("Error"), 0);
		num = ft_atol(numbers[i]);
		if (has_duplicate(*stack_a, (int)num))
			return (safe_exit(stack_a, numbers), ft_error("Error"), 0);
		push(stack_a, (int)num);
		i++;
	}
	safe_exit(NULL, numbers);
	return (1);
}


