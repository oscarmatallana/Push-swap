/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:59:18 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:36:27 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	stack_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

void	build_stack(t_stack *stack, t_config *config)
{
	t_node	*new_node;
	int		i;
	int		nbr;

	i = 0;
	while (config->tokens[i])
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
		{
			free_stack(stack);
			free_str_array(config->tokens);
			ft_printf_fd(2, "Error\n");
			exit(1);
		}
		nbr = (int)ft_atol(config->tokens[i]);
		new_node->value = nbr;
		append_node(stack, new_node);
		i++;
		stack->size++;
	}
}
