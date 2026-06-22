/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:47:26 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:34:34 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static long	convert_digits(const char *str, int i, int symbol)
{
	long	result;
	long	limit;
	int		digit;

	result = 0;
	limit = INT_MAX;
	if (symbol < 0)
		limit = -(long)INT_MIN;
	while (ft_isdigit(str[i]))
	{
		digit = str[i] - '0';
		if (result > (limit - digit) / 10)
		{
			if (symbol < 0)
				return (LONG_MIN);
			return (LONG_MAX);
		}
		result = result * 10 + digit;
		i++;
	}
	return (result * symbol);
}

long	ft_atol(const char *str)
{
	int	i;
	int	symbol;

	i = 0;
	symbol = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			symbol = -symbol;
		i++;
	}
	return (convert_digits(str, i, symbol));
}

int	ft_int_sqrt(int number)
{
	int	root;

	if (number <= 0)
		return (0);
	if (number == 1)
		return (1);
	root = 0;
	while (root + 1 <= number / (root + 1))
		root++;
	return (root);
}
