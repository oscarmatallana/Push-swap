/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:21:54 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:34:39 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_str_array(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

void	error_n_free(char **tokens, int *nums)
{
	if (nums)
		free(nums);
	free_str_array(tokens);
}

int	syntax_error(char *token)
{
	int	i;

	i = 0;
	if (!(ft_isdigit(token[i]) || token[i] == '-' || token[i] == '+'))
		return (1);
	if ((token[i] == '+' || token[i] == '-') && !ft_isdigit(token[i + 1]))
		return (1);
	i++;
	while (token[i])
	{
		if (!ft_isdigit(token[i]))
			return (1);
		i++;
	}
	return (0);
}

int	repetition_error(long nbr, int *nums, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (nums[j] == nbr)
			return (1);
		j++;
	}
	return (0);
}
