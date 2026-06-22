/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:10:35 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:42:13 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	compute_disorder(t_stack *a, t_config *config)
{
	int		mistakes;
	int		total_pairs;
	t_node	*node1;
	t_node	*node2;

	mistakes = 0;
	total_pairs = 0;
	node1 = a->top;
	while (node1)
	{
		node2 = node1->next;
		while (node2)
		{
			total_pairs++;
			if (node1->value > node2->value)
				mistakes++;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	if (total_pairs == 0)
		config->disorder = 0.0f;
	else
		config->disorder = (float)mistakes / total_pairs;
}

void	strategy_picker(t_config *config)
{
	if (config->strategy == ADAPTIVE)
	{
		config->adaptive = true;
		if (config->disorder < 0.2f)
			config->strategy = SIMPLE;
		else if (config->disorder >= 0.2f && config->disorder < 0.5f)
			config->strategy = MEDIUM;
		else
			config->strategy = COMPLEX;
	}
}
