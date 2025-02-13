/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:00:19 by adamarqu          #+#    #+#             */
/*   Updated: 2025/02/12 19:27:52 by adamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				index;
}	t_stack;

t_stack    *create_node(int value);
void        push(t_stack **head, int new_data);
void        free_stack(t_stack **head);
int         stack_size(t_stack *head);
int         is_sorted(t_stack *head);

#endif
