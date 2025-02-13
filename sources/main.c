/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:59:22 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 16:03:53 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_stack_str(char *str)
{
	t_stack	*stack_a = NULL;
	char		**numbers;
	int			i;
	int			num;

	numbers = ft_split(str, ' ');
	if (!numbers)
		return (NULL);

	i = 0;
	while (numbers[i])
	{
		if (!is_valid_argument(numbers[i])) 
		{
			safe_exit(&stack_a, numbers);
			return (NULL);
		}
		num = ft_atoi(numbers[i]);
		push(&stack_a, num);
		i++;
	}
	safe_exit(NULL, numbers); 
	return (stack_a);
}

t_stack	*create_stack_arr(int argc, char **argv)
{
	t_stack	*stack_a;
	int			i;
	int			num;

	i = 1;
	stack_a = NULL;
	num = 0;
	while (i < argc)
	{
		if(!is_valid_argument(argv[i]))
		{
            free_stack(&stack_a);
            return (NULL);
        }
		num = ft_atoi(argv[i]);
		push(&stack_a, num);
		i++;
	}
	return (stack_a);		
}
t_stack    *parse_arguments(int argc, char **argv)
{
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		return (create_stack_str(argv[1]));
	else
		return (create_stack_arr(argc, argv));
}	

/*int	main(int argc, char **argv)  // Main to test nodes
{
	t_stack	*stack_a;
	t_stack 	*current;
	int			index = 0;

	stack_a = parse_arguments(argc, argv);
	if (stack_a == NULL)
	{
		ft_error("Error");
		return (1);
	}
	if (argc < 2)
		return (0);
	current = stack_a;
	ft_printf("Stack A:\n");
	while (current != NULL)
	{
		ft_printf("Node %d: Value = %d, Address = %p, Next = %p\n", 
		          index, current->value, (void *)current, (void *)current->next);
		current = current->next;
		index++;
	}
	
	free_stack(&stack_a);
	return (0);
}*/

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int size;

    if (argc < 2)
        return (0);
    stack_a = parse_arguments(argc, argv);
    if (!stack_a)
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    stack_b = NULL;
    size = stack_size(stack_a);
	/*f (has_duplicate(stack_a, stack_a->value))
	{
    	free_stack(&stack_a);
		stack_a = NULL;
    	ft_error("Error");
    	return (1);
	}*/
    if (is_sorted(stack_a))
    return (free_stack(&stack_a), 0);
    if (size == 2)
        sa(&stack_a);
    else if (size == 3)
        sort_three(&stack_a);
    else if (size <= 5)
        sort_five(&stack_a, &stack_b);
    else
		assign_indexes(stack_a);
        radix_sort(&stack_a, &stack_b);

    free_stack(&stack_a);
    free_stack(&stack_b);

    return (0);
}

