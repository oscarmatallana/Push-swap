/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:14:27 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 16:38:30 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	Make sure ./push_swap 1 2 3 and ./push_swap "1 2 3" behave the same

*/

#include "../inc/push_swap.h"

static char	**multiple_args(int argc, char **argv, int start_index);

char	**parse_numbers(int argc, char **argv, int start_index)
{
	char	**tokens;

	if (start_index >= argc)
		return (NULL);
	if (argc - start_index == 1)
		tokens = ft_split(argv[start_index], ' ');
	else
		tokens = multiple_args(argc, argv, start_index);
	if (!tokens)
		return (NULL);
	if (!validate_nums(tokens))
		return (NULL);
	return (tokens);
}

static char	**multiple_args(int argc, char **argv, int start_index)
{
	int		arg_count;
	int		i;
	char	**tokens;

	arg_count = argc - start_index;
	tokens = ft_calloc(arg_count + 1, sizeof(char *));
	if (!tokens)
		return (NULL);
	i = 0;
	while (i < arg_count)
	{
		tokens[i] = ft_strdup(argv[start_index + i]);
		if (!tokens[i])
			return (free_str_array(tokens), NULL);
		i++;
	}
	return (tokens);
}
