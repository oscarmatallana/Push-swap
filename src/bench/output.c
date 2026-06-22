/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:01:46 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:42:24 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	print_disorder(t_config *config);
static void	print_strategy(t_config *config);
static void	print_total_ops(t_config *config);
static void	print_individual_ops(t_config *config);

void	print_bench(t_config *config)
{
	print_disorder(config);
	print_strategy(config);
	print_total_ops(config);
	print_individual_ops(config);
}

static void	print_disorder(t_config *config)
{
	int	percent;
	int	whole;
	int	decimal;

	percent = (int)(config->disorder * 10000.0f + 0.5f);
	whole = percent / 100;
	decimal = percent % 100;
	if (decimal < 10)
		ft_printf_fd(2, "[bench] disorder: %d.0%d%%\n", whole, decimal);
	else
		ft_printf_fd(2, "[bench] disorder: %d.%d%%\n", whole, decimal);
}

static void	print_strategy(t_config *config)
{
	if (config->strategy == SIMPLE && config->adaptive == true)
		ft_printf_fd(2, "[bench] strategy: Adaptive / O(n²)\n");
	else if (config->strategy == MEDIUM && config->adaptive == true)
		ft_printf_fd(2, "[bench] strategy: Adaptive / O(n√n)\n");
	else if (config->strategy == COMPLEX && config->adaptive == true)
		ft_printf_fd(2, "[bench] strategy: Adaptive / O(nlogn)\n");
	else if (config->strategy == SIMPLE)
		ft_printf_fd(2, "[bench] strategy: Simple / O(n²)\n");
	else if (config->strategy == MEDIUM)
		ft_printf_fd(2, "[bench] strategy: Medium / O(n√n)\n");
	else if (config->strategy == COMPLEX)
		ft_printf_fd(2, "[bench] strategy: Complex / O(nlogn)\n");
}

static void	print_total_ops(t_config *config)
{
	ft_printf_fd(2, "[bench] total ops: %d\n", config->total_ops);
}

static void	print_individual_ops(t_config *config)
{
	ft_printf_fd(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", config->sa,
		config->sb, config->ss, config->pa, config->pb);
	ft_printf_fd(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		config->ra, config->rb, config->rr, config->rra, config->rrb,
		config->rrr);
}
