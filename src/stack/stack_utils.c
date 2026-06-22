/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:21:57 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:36:42 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	append_node(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	if (!stack->top)
	{
		stack->top = node;
		stack->bottom = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		stack->bottom->next = node;
		node->next = NULL;
		node->prev = stack->bottom;
		stack->bottom = node;
	}
}

void	bring_min_to_top_of(t_stack *a, t_config *config)
{
	t_node	*current;
	int		min_value;
	int		min_value_index;
	int		i;

	current = a->top;
	min_value = current->value;
	min_value_index = 0;
	i = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_value_index = i;
		}
		i++;
		current = current->next;
	}
	if (min_value_index <= a->size / 2)
		while (a->top->value != min_value)
			ra(a, config);
	else
		while (a->top->value != min_value)
			rra(a, config);
}

void	bring_max_to_top_of(t_stack *b, t_config *config)
{
	t_node	*current;
	int		max_value;
	int		max_value_index;
	int		i;

	current = b->top;
	max_value = current->value;
	max_value_index = 0;
	i = 0;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_value_index = i;
		}
		i++;
		current = current->next;
	}
	if (max_value_index <= b->size / 2)
		while (b->top->value != max_value)
			rb(b, config);
	else
		while (b->top->value != max_value)
			rrb(b, config);
}
