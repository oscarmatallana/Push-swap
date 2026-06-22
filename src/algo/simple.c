/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:19:40 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:43:41 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	Min extraction method:

	Look at the current stack a
	Find the minimum value
	Rotate a so that value reaches the top
	Push it to b
	Repeat until a is small enough to finish directly
	Sort the remaining tiny core
	Push everything back

*/

#include "../inc/push_swap.h"

void	simple_sort(t_stack *a, t_stack *b, t_config *config)
{
	if (a->size <= 5)
		tiny_sort(a, b, config);
	else
		extract_min_to_three(a, b, config);
}
