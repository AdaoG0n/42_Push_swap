/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:32:08 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/21 16:14:46 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	split_str(char *str, t_stack *stack)
{
	char	**split;
	int		i;
	int		num;

	i = 0;
	split = ft_split(str, ' ');
	if (split == NULL)
		return (0);
	while (split[i])
	{
		if (!valid_args(split[i], stack))
			return (ft_free(split), 0);
		num = ft_atol(split[i]);
		append(stack, (int)num);
		i++;
	}
	ft_free(split);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *stack_a)
{
	int		num;
	int		i;

	i = 1;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		if (!split_str(argv[1], stack_a))
			return (0);
	}
	else if (argc > 2)
	{
		while (i < argc)
		{
			if (!valid_args(argv[i], stack_a))
				return (0);
			num = ft_atol(argv[i]);
			append(stack_a, (int)num);
			i++;
		}
	}
	return (1);
}

int	handle_input(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	char **new_argv;
	int i = 1;
	int num;

	if (argc < 2)
		return (0);

	if (argc == 2)
	{
		new_argv = ft_split(argv[1], ' ');
		if (!new_argv)
			return (ft_error("Error"), free_stack(stack_a), free_stack(stack_b), 1);
	}
	else
	{
		new_argv = argv + 1;
	}

	new_argv = check_input(new_argv);
	if (!new_argv)
		return (ft_error("Error"), free_stack(stack_a), free_stack(stack_b), 1);

	if (argc == 2)
	{
		while (new_argv[i])
		{
			num = ft_atol(new_argv[i]);
			append(stack_a, (int)num);
			i++;
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			num = ft_atol(argv[i]);
			append(stack_a, (int)num);
			i++;
		}
	}
	sort_and_clean(stack_a, stack_b);
	return (free_stack(stack_a), free_stack(stack_b), 0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_stack();
	stack_b = create_stack();
	if (!stack_a || !stack_b)
	{
		if (stack_a)
			free_stack(stack_a);
		if (stack_b)
			free_stack(stack_b);
		return (ft_error("Error"), 1);
	}
	handle_input(argc, argv, stack_a, stack_b);
	return (0);
}
