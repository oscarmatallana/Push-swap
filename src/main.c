/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:22:55 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:34:20 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	config;

	if (argc == 1)
		return (0);
	stack_init(&a);
	stack_init(&b);
	parse_input(argc, argv, &config);
	build_stack(&a, &config);
	compute_disorder(&a, &config);
	strategy_picker(&config);
	if (config.disorder > 0.0f)
		choose_algo(&a, &b, &config);
	if (config.bench == true)
		print_bench(&config);
	free_stack(&a);
	free_stack(&b);
	free_str_array(config.tokens);
	return (0);
}
