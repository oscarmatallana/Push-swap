/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:18:30 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:18:34 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	checker_error_n_free(t_stack *a, t_stack *b, t_config *config,
		char *line)
{
	free(line);
	free_stack(a);
	free_stack(b);
	free_str_array(config->tokens);
	ft_printf_fd(2, "Error\n");
	exit(1);
}

static void	execute_input_operation(t_stack *a, t_stack *b, t_config *config,
		char *line)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		sa(a, config);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		sb(b, config);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		ss(a, b, config);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		pa(a, b, config);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		pb(a, b, config);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		ra(a, config);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		rb(b, config);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		rr(a, b, config);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		rra(a, config);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		rrb(b, config);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		rrr(a, b, config);
	else
		checker_error_n_free(a, b, config, line);
}

void	handle_input(t_stack *a, t_stack *b, t_config *config)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_input_operation(a, b, config, line);
		free(line);
		line = get_next_line(0);
	}
}

void	check_if_sorted(t_stack *a, t_stack *b)
{
	t_node	*current;

	if (b->size > 0)
	{
		ft_printf("KO\n");
		return ;
	}
	current = a->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
		{
			ft_printf("KO\n");
			return ;
		}
		current = current->next;
	}
	ft_printf("OK\n");
}
