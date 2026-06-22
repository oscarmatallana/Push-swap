/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:13:14 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:22:49 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	parse_flags(char *arg, t_config *config)
{
	if (ft_strncmp(arg, "--simple", 9) == 0 && arg[8] == '\0'
		&& !config->strategy_picked)
	{
		config->strategy = SIMPLE;
		return (config->strategy_picked = true, 1);
	}
	if (ft_strncmp(arg, "--medium", 9) == 0 && arg[8] == '\0'
		&& !config->strategy_picked)
	{
		config->strategy = MEDIUM;
		return (config->strategy_picked = true, 1);
	}
	if (ft_strncmp(arg, "--complex", 10) == 0 && arg[9] == '\0'
		&& !config->strategy_picked)
	{
		config->strategy = COMPLEX;
		return (config->strategy_picked = true, 1);
	}
	if (ft_strncmp(arg, "--adaptive", 11) == 0 && arg[10] == '\0'
		&& !config->strategy_picked)
		return (config->strategy_picked = true, 1);
	if (ft_strncmp(arg, "--bench", 8) == 0 && arg[7] == '\0')
		return (config->bench = true, 1);
	return (0);
}

/* check for argv flags: 
--simple
--medium
--complex
--adaptive
--bench*/