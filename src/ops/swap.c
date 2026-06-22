/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:03:24 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:41:17 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Swap ops like sa, sb, ss

sa (swap a): Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

*/

#include "../inc/push_swap.h"

static void	swap(t_stack *stack);

void	sa(t_stack *a, t_config *config)
{
	if (!a->top || !a->top->next)
		return ;
	swap(a);
	if (!config->checker)
	{
		config->total_ops++;
		config->sa++;
		ft_printf("sa\n");
	}
}

void	sb(t_stack *b, t_config *config)
{
	if (!b->top || !b->top->next)
		return ;
	swap(b);
	if (!config->checker)
	{
		config->total_ops++;
		config->sb++;
		ft_printf("sb\n");
	}
}

void	ss(t_stack *a, t_stack *b, t_config *config)
{
	if ((!a->top || !a->top->next) && (!b->top || !b->top->next))
		return ;
	swap(a);
	swap(b);
	if (!config->checker)
	{
		config->total_ops++;
		config->ss++;
		ft_printf("ss\n");
	}
}

static void	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	if (!stack->top || !stack->top->next)
		return ;
	node1 = stack->top;
	node2 = node1->next;
	node3 = node2->next;
	if (node3)
	{
		node3->prev = node1;
		node1->next = node3;
	}
	else
	{
		stack->bottom = node1;
		node1->next = NULL;
	}
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	stack->top = node2;
}
