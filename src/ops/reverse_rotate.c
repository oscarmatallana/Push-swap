/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:52:30 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:40:42 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

rra (reverse rotate a): Shift down all elements of stack a by one.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by one.
The last element becomes the first one.

rrr : rra and rrb at the same time.

*/

#include "../inc/push_swap.h"

static void	reverse_rotate(t_stack *stack);

void	rra(t_stack *a, t_config *config)
{
	if (!a->top || !a->top->next)
		return ;
	reverse_rotate(a);
	if (!config->checker)
	{
		config->total_ops++;
		config->rra++;
		ft_printf("rra\n");
	}
}

void	rrb(t_stack *b, t_config *config)
{
	if (!b->top || !b->top->next)
		return ;
	reverse_rotate(b);
	if (!config->checker)
	{
		config->total_ops++;
		config->rrb++;
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack *a, t_stack *b, t_config *config)
{
	if ((!a->top || !a->top->next) && (!b->top || !b->top->next))
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	if (!config->checker)
	{
		config->total_ops++;
		config->rrr++;
		ft_printf("rrr\n");
	}
}

static void	reverse_rotate(t_stack *stack)
{
	t_node	*node_to_be_rotated;

	if (!stack->top || !stack->top->next)
		return ;
	node_to_be_rotated = stack->bottom;
	stack->bottom = node_to_be_rotated->prev;
	stack->bottom->next = NULL;
	node_to_be_rotated->next = stack->top;
	node_to_be_rotated->prev = NULL;
	stack->top->prev = node_to_be_rotated;
	stack->top = node_to_be_rotated;
}
