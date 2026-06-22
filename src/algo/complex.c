/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:54:11 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:43:19 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	Radix sort adaptation (bitwise sorting with two stacks):

	Copy all values from a into an array DONE
	sort / normalize values into ranks 0 -> n - 1 DONE
	find max rank and number of bits needed TODO
	for each bit position from 0 to max_bits - 1 TODO
	start from top of a
	if current value has bit 0 at this position, pb to b
	if current value has bit 1 at this position, ra
	repeat until all values in a were checked
	while b is not empty, pa back to a
	repeat for next bit
	after last bit, stack a is sorted

*/

#include "../inc/push_swap.h"

static void	sort_bitwise(t_stack *a, t_stack *b, t_config *config, int size_a);

void	complex_sort(t_stack *a, t_stack *b, t_config *config)
{
	int	size_a;

	size_a = a->size;
	if (size_a <= 5)
		tiny_sort(a, b, config);
	else
	{
		rank_stack_values_of(a, config);
		sort_bitwise(a, b, config, size_a);
	}
}

static int	find_max_bits(int max_value_of_stack)
{
	int	bits;

	bits = 0;
	while (max_value_of_stack >> bits)
		bits++;
	return (bits);
}

static void	push_or_ra(t_stack *a, t_stack *b, t_config *config, int bit)
{
	if (((a->top->value >> bit) & 1) == 0)
		pb(a, b, config);
	else
		ra(a, config);
}

static void	sort_bitwise(t_stack *a, t_stack *b, t_config *config, int size_a)
{
	int	max_bits;
	int	i;
	int	j;

	max_bits = find_max_bits(size_a - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size_a)
		{
			push_or_ra(a, b, config, i);
			j++;
		}
		while (b->top)
			pa(a, b, config);
		i++;
	}
}
