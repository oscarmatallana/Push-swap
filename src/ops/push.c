/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:49:57 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:40:25 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

*/

#include "../inc/push_swap.h"

static void	push(t_stack *src, t_stack *dst);

void	pa(t_stack *a, t_stack *b, t_config *config)
{
	if (!b->top)
		return ;
	push(b, a);
	if (!config->checker)
	{
		config->total_ops++;
		config->pa++;
		ft_printf("pa\n");
	}
}

void	pb(t_stack *a, t_stack *b, t_config *config)
{
	if (!a->top)
		return ;
	push(a, b);
	if (!config->checker)
	{
		config->total_ops++;
		config->pb++;
		ft_printf("pb\n");
	}
}

static void	push(t_stack *src, t_stack *dst)
{
	t_node	*node_to_be_pushed;

	if (!src->top)
		return ;
	node_to_be_pushed = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	node_to_be_pushed->prev = NULL;
	if (!dst->top)
	{
		dst->top = node_to_be_pushed;
		dst->bottom = node_to_be_pushed;
		node_to_be_pushed->next = NULL;
	}
	else
	{
		node_to_be_pushed->next = dst->top;
		node_to_be_pushed->next->prev = node_to_be_pushed;
		dst->top = node_to_be_pushed;
	}
	src->size--;
	dst->size++;
}
