/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:17:39 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:18:08 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

enum				e_strategy
{
	ADAPTIVE = 0,
	SIMPLE = 1,
	MEDIUM = 2,
	COMPLEX = 3
};

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	int				size;
	t_node			*top;
	t_node			*bottom;
}					t_stack;

typedef struct s_config
{
	int				num_start;
	enum e_strategy	strategy;
	bool			strategy_picked;
	bool			adaptive;
	bool			bench;
	bool			checker;
	char			**tokens;
	float			disorder;
	int				total_ops;
	int				pa;
	int				pb;
	int				rra;
	int				rrb;
	int				rrr;
	int				ra;
	int				rb;
	int				rr;
	int				sa;
	int				sb;
	int				ss;
}					t_config;

typedef struct s_chunk
{
	int				size;
	int				start;
	int				end;
	int				pushed;
	int				count;
	int				total;
	int				mid;
}					t_chunk;

/* ---------------	STACK	--------------- */
void				stack_init(t_stack *stack);
void				build_stack(t_stack *stack, t_config *config);
void				append_node(t_stack *stack, t_node *node);
void				bring_min_to_top_of(t_stack *a, t_config *config);
void				bring_max_to_top_of(t_stack *b, t_config *config);
void				free_stack(t_stack *stack);

/* ---------------	PARSER	--------------- */
void				parse_input(int argc, char **argv, t_config *config);
int					parse_flags(char *arg, t_config *config);
char				**parse_numbers(int argc, char **argv, int start_index);
bool				validate_nums(char **tokens);

/* ---------------	ALGOS --------------- */
void				choose_algo(t_stack *a, t_stack *b, t_config *config);
void				strategy_picker(t_config *config);
void				extract_min_to_three(t_stack *a, t_stack *b,
						t_config *config);
void				tiny_sort(t_stack *a, t_stack *b, t_config *config);
void				simple_sort(t_stack *a, t_stack *b, t_config *config);
void				medium_sort(t_stack *a, t_stack *b, t_config *config);
void				complex_sort(t_stack *a, t_stack *b, t_config *config);

/* ---------------	OPERATIONS	--------------- */
void				sa(t_stack *a, t_config *config);
void				sb(t_stack *b, t_config *config);
void				ss(t_stack *a, t_stack *b, t_config *config);
void				pa(t_stack *a, t_stack *b, t_config *config);
void				pb(t_stack *a, t_stack *b, t_config *config);
void				ra(t_stack *a, t_config *config);
void				rb(t_stack *b, t_config *config);
void				rr(t_stack *a, t_stack *b, t_config *config);
void				rra(t_stack *a, t_config *config);
void				rrb(t_stack *b, t_config *config);
void				rrr(t_stack *a, t_stack *b, t_config *config);

/* ---------------	UTILS	--------------- */
void				error_n_free(char **tokens, int *nums);
void				free_str_array(char **tokens);
long				ft_atol(const char *str);
int					syntax_error(char *token);
int					repetition_error(long nbr, int *nums, int i);
void				rank_stack_values_of(t_stack *a, t_config *config);
int					ft_int_sqrt(int number);

/* ---------------	BENCH	--------------- */
void				compute_disorder(t_stack *a, t_config *config);
void				print_bench(t_config *config);

/* ---------------	CHECKER	--------------- */
void				handle_input(t_stack *a, t_stack *b, t_config *config);
void				check_if_sorted(t_stack *a, t_stack *b);

#endif
