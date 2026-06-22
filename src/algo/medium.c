/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:54:00 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:43:33 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	Chunk-based sorting (divide into √n chunks):

	Collect and store all values from a in a copy
	sort copies
	turn each value to a rank 0 -> n - 1 (n = amount of numbers in total)
	Push based on √n chunks
	Look at a
	Start from a->top
	check rank of value, push b when in top ranks,
		if not ra until a value from chunk 1 comes to the top
	optionally rb if in lower half of chunk
	repeat until a empty
	while b is not empty
	move max value in b to top of b
	pa

*/

#include "../inc/push_swap.h"

static void	push_chunks_to_b(t_stack *a, t_stack *b, t_config *config);

void	medium_sort(t_stack *a, t_stack *b, t_config *config)
{
	if (a->size <= 5)
		tiny_sort(a, b, config);
	else
	{
		rank_stack_values_of(a, config);
		push_chunks_to_b(a, b, config);
		while (b->top)
		{
			bring_max_to_top_of(b, config);
			pa(a, b, config);
		}
	}
}

static void	push_chunk_value_to_b(t_stack *a, t_stack *b, t_config *config,
		t_chunk *chunk)
{
	int	top_value;

	top_value = a->top->value;
	pb(a, b, config);
	if (chunk->mid >= top_value && b->size > 1)
		rb(b, config);
	chunk->pushed++;
}

static void	update_chunk(t_chunk *chunk)
{
	chunk->start += chunk->size;
	chunk->end += chunk->size;
	if (chunk->end >= chunk->total)
		chunk->end = chunk->total - 1;
	chunk->mid = (chunk->start + chunk->end) / 2;
}

static void	push_chunks_to_b(t_stack *a, t_stack *b, t_config *config)
{
	t_chunk	chunk;

	chunk.total = a->size;
	chunk.size = ft_int_sqrt(chunk.total) * 3;
	chunk.start = 0;
	chunk.end = chunk.size - 1;
	chunk.mid = (chunk.start + chunk.end) / 2;
	while (a->top)
	{
		chunk.count = chunk.end - chunk.start + 1;
		chunk.pushed = 0;
		while (chunk.pushed < chunk.count)
		{
			if (a->top->value >= chunk.start && a->top->value <= chunk.end)
				push_chunk_value_to_b(a, b, config, &chunk);
			else
				ra(a, config);
		}
		update_chunk(&chunk);
	}
}
