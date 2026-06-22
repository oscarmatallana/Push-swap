/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:20:13 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:40:55 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

ra (rotate a): Shift up all elements of stack a by one.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by one.
The first element becomes the last one.

rr : ra and rb at the same time.


*/

#include "../inc/push_swap.h"

static void	rotate(t_stack *stack);

void	ra(t_stack *a, t_config *config)
{
	if (!a->top || !a->top->next)
		return ;
	rotate(a);
	if (!config->checker)
	{
		config->total_ops++;
		config->ra++;
		ft_printf("ra\n");
	}
}

void	rb(t_stack *b, t_config *config)
{
	if (!b->top || !b->top->next)
		return ;
	rotate(b);
	if (!config->checker)
	{
		config->total_ops++;
		config->rb++;
		ft_printf("rb\n");
	}
}

void	rr(t_stack *a, t_stack *b, t_config *config)
{
	if ((!a->top || !a->top->next) && (!b->top || !b->top->next))
		return ;
	rotate(a);
	rotate(b);
	if (!config->checker)
	{
		config->total_ops++;
		config->rr++;
		ft_printf("rr\n");
	}
}

static void	rotate(t_stack *stack)
{
	t_node	*node_to_be_rotated;

	if (!stack->top || !stack->top->next)
		return ;
	node_to_be_rotated = stack->top;
	stack->top = node_to_be_rotated->next;
	stack->top->prev = NULL;
	node_to_be_rotated->next = NULL;
	node_to_be_rotated->prev = stack->bottom;
	stack->bottom->next = node_to_be_rotated;
	stack->bottom = node_to_be_rotated;
}
