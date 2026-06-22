# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/22 16:53:17 by omatalla          #+#    #+#              #
#    Updated: 2026/06/22 16:53:23 by omatalla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = push_swap

BONUS_NAME = checker

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

INC = -Iinc -I$(LIBFT_DIR)

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = src/main.c \
	src/algo/choose_algo.c \
	src/algo/complex.c \
	src/algo/medium.c \
	src/algo/simple.c \
	src/algo/tiny_sort.c \
	src/bench/disorder.c \
	src/bench/output.c \
	src/ops/push.c \
	src/ops/reverse_rotate.c \
	src/ops/rotate.c \
	src/ops/swap.c \
	src/parse/flags.c \
	src/parse/input.c \
	src/parse/numbers.c \
	src/parse/validation.c \
	src/stack/stack_setup.c \
	src/stack/stack_free.c \
	src/stack/stack_utils.c \
	src/utils/error_handle.c \
	src/utils/helpers.c \
	src/utils/algo_utils.c

OBJS = $(SRCS:.c=.o)

CHECKER_SRCS = bonus/checker.c \
	bonus/checker_utils.c \
	src/ops/push.c \
	src/ops/reverse_rotate.c \
	src/ops/rotate.c \
	src/ops/swap.c \
	src/parse/numbers.c \
	src/parse/validation.c \
	src/stack/stack_setup.c \
	src/stack/stack_free.c \
	src/stack/stack_utils.c \
	src/utils/error_handle.c \
	src/utils/helpers.c

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS) $(CHECKER_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re test count
