/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:42:20 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:34:44 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Dedicated file for sort algorithm utility functions.
*/

#include "../inc/push_swap.h"

static int	*copy_stack_into_array(t_stack *a);
static void	sort_array(int *copied_array, int stack_size);
static void	turn_stack_value_into_rank(t_stack *a, int *sorted_array);

void	rank_stack_values_of(t_stack *a, t_config *config)
{
	int	*copy_of_stack;

	copy_of_stack = copy_stack_into_array(a);
	if (!copy_of_stack)
	{
		free_stack(a);
		free_str_array(config->tokens);
		ft_printf_fd(2, "Error\n");
		exit(1);
	}
	sort_array(copy_of_stack, a->size);
	turn_stack_value_into_rank(a, copy_of_stack);
	free(copy_of_stack);
}

static int	*copy_stack_into_array(t_stack *a)
{
	int		*copy_of_stack;
	int		i;
	t_node	*current;

	copy_of_stack = malloc(sizeof(int) * a->size);
	if (!copy_of_stack)
		return (NULL);
	current = a->top;
	i = 0;
	while (current)
	{
		copy_of_stack[i++] = current->value;
		current = current->next;
	}
	return (copy_of_stack);
}

static void	sort_array(int *copied_array, int stack_size)
{
	int	min_index;
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < stack_size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < stack_size)
		{
			if (copied_array[j] < copied_array[min_index])
				min_index = j;
			j++;
		}
		if (min_index != i)
		{
			temp = copied_array[i];
			copied_array[i] = copied_array[min_index];
			copied_array[min_index] = temp;
		}
		i++;
	}
}

static void	turn_stack_value_into_rank(t_stack *a, int *sorted_array)
{
	t_node	*current;
	int		i;

	current = a->top;
	i = 0;
	while (current)
	{
		i = 0;
		while (i < a->size)
		{
			if (current->value == sorted_array[i])
			{
				current->value = i;
				break ;
			}
			else
				i++;
		}
		current = current->next;
	}
}
