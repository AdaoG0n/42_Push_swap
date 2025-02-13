/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:59:22 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/13 23:15:54 by adamarqu         ###   ########.fr       */
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

// void test_operations(t_stack **stack_a, t_stack **stack_b)
// {
//     ft_printf("Initial stack A:\n");
//     print_stack(*stack_a, "A");

//     // Test sa
//     sa(stack_a);
//     ft_printf("After sa:\n");
//     print_stack(*stack_a, "A");

//     // Test pb
//     pb(stack_a, stack_b);
//     ft_printf("After pb:\n");
//     print_stack(*stack_a, "A");
//     print_stack(*stack_b, "B");

//     // Test pa
//     pa(stack_a, stack_b);
//     ft_printf("After pa:\n");
//     print_stack(*stack_a, "A");
//     print_stack(*stack_b, "B");

//     // Test ra
//     ra(stack_a);
//     ft_printf("After ra:\n");
//     print_stack(*stack_a, "A");

//     // Test rra
//     rra(stack_a);
//     ft_printf("After rra:\n");
//     print_stack(*stack_a, "A");

//     // Test rb
//     pb(stack_a, stack_b); // Move one element to stack B for testing
//     rb(stack_b);
//     ft_printf("After rb:\n");
//     print_stack(*stack_a, "A");
//     print_stack(*stack_b, "B");

//     // Test rrb
//     rrb(stack_b);
//     ft_printf("After rrb:\n");
//     print_stack(*stack_a, "A");
//     print_stack(*stack_b, "B");

//     // Test ss
//     sa(stack_a);
//     pb(stack_a, stack_b);
//     sb(stack_b);
//     ss(stack_a, stack_b);
//     ft_printf("After ss:\n");
//     print_stack(*stack_a, "A");
//     print_stack(*stack_b, "B");

//     // Test rr
//     ra(stack_a);
//     rb(stack_b);
//     rr(stack_a, stack_b);
//     ft_printf("After rr:\n");
//     print_stack(*stack_a, "A");
//     print_stack(*stack_b, "B");

//     // Test rrr
//     rra(stack_a);
//     rrb(stack_b);
//     rrr(stack_a, stack_b);
//     ft_printf("After rrr:\n");
//     print_stack(*stack_a, "A");
//     print_stack(*stack_b, "B");
// }

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = parse_arguments(argc, argv);
    stack_b = NULL;

    // Inicializar índices como -1
    t_stack *temp = stack_a;
    while (temp)
    {
        temp->index = -1;
        temp = temp->next;
    }

    int size = stack_size(stack_a);
    if (size == 2)
        sa(&stack_a);
    else if (size == 3)
        sort_three(&stack_a);
    else if (size <= 5)
        sort_five(&stack_a, &stack_b);
    else
    {
        assign_indexes(stack_a);
        radix_sort(&stack_a, &stack_b);
    }

    // Print the sorted stack for verification
     print_stack(stack_a, "A");

    // Free the stacks
    free_stack(&stack_a);
    free_stack(&stack_b);

    return 0;
}