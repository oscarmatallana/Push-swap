/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:35:00 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:38:45 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	check the created **tokens for any invalid formats, 
	INT_MAX / INT_MIN, RANGE, DUPES

*/

#include "../inc/push_swap.h"

static int	token_count(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

bool	validate_nums(char **tokens)
{
	long	nbr;
	int		i;
	int		*nums;

	i = token_count(tokens);
	if (i == 0)
		return (free_str_array(tokens), false);
	nums = malloc(sizeof(int) * i);
	if (!nums)
		return (free_str_array(tokens), false);
	i = 0;
	while (tokens[i])
	{
		if (syntax_error(tokens[i]))
			return (error_n_free(tokens, nums), false);
		nbr = ft_atol(tokens[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (error_n_free(tokens, nums), false);
		if (repetition_error(nbr, nums, i))
			return (error_n_free(tokens, nums), false);
		nums[i] = (int)nbr;
		i++;
	}
	free(nums);
	return (true);
}
