/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:04:18 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:43:06 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	choose_algo(t_stack *a, t_stack *b, t_config *config)
{
	if (config->strategy == SIMPLE)
		simple_sort(a, b, config);
	else if (config->strategy == MEDIUM)
		medium_sort(a, b, config);
	else
		complex_sort(a, b, config);
}
