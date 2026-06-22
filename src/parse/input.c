/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:28:46 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:38:20 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	config_init(t_config *config)
{
	config->num_start = 1;
	config->strategy = ADAPTIVE;
	config->strategy_picked = false;
	config->adaptive = false;
	config->bench = false;
	config->checker = false;
	config->tokens = NULL;
	config->disorder = 0.0f;
	config->total_ops = 0;
	config->pa = 0;
	config->pb = 0;
	config->ra = 0;
	config->rb = 0;
	config->rr = 0;
	config->rra = 0;
	config->rrb = 0;
	config->rrr = 0;
	config->sa = 0;
	config->sb = 0;
	config->ss = 0;
}

void	parse_input(int argc, char **argv, t_config *config)
{
	int	i;

	i = 1;
	config_init(config);
	while (i < argc)
	{
		if (parse_flags(argv[i], config))
			i++;
		else
			break ;
	}
	config->num_start = i;
	config->tokens = parse_numbers(argc, argv, config->num_start);
	if (!config->tokens)
	{
		ft_printf_fd(2, "Error\n");
		exit(1);
	}
}
