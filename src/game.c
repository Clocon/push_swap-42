/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:44:46 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/29 14:01:06 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	short_moves(t_stacks *stack)
{
	int	i;

	i = 6;
	while (--i >= stack->size)
	{
		if (is_completed(stack) == 1)
			exit(0);
		if (stack->size == 5)
			five(stack, 0);
		else if (stack->size == 4)
			four(stack, 0);
		else if (stack->size == 3)
			three(stack);
		else if (stack->size == 2)
			two(stack);
	}
	while (stack->b[0] != -1)
		push_a(stack, 1);
	free(stack->a);
	free(stack->b);
	exit(0);
}

int	is_completed(t_stacks *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size)
	{
		if (stack->a[i] != i)
			return (0);
	}
	return (1);
}

int	is_sorted(t_stacks *stack)
{
	int	i;

	i = -1;
	while (++i < arr_size(stack->a, stack->size) - 1)
	{
		if (stack->a[i + 1] - stack->a[i] != 1)
			return (0);
	}
	return (1);
}

void	move_a(t_stacks *stack, int n_bits)
{
	int	i;
	int	pre_size;

	i = -1;
	pre_size = arr_size(stack->a, stack->size);
	while (++i < pre_size)
	{
		if (is_sorted(stack) == 1)
			return ;
		if (((stack->a[0] >> n_bits) & 1) == 0)
			push_b(stack, 1);
		else
			rotate_a(stack->a, arr_size(stack->a, stack->size), 1);
	}
}

void	move_b(t_stacks *stack, int max_bits, int n_bits)
{
	int	i;
	int	size_b;

	size_b = arr_size(stack->b, stack->size);
	i = -1;
	while (++i < size_b)
	{
		if (is_completed(stack) == 1)
			return ;
		if (n_bits < max_bits - 1)
		{
			if (((stack->b[0] >> (n_bits + 1)) & 1) == 0)
				rotate_b(stack->b, stack->size, 1);
			else
				push_a(stack, 1);
		}
		else
			push_a(stack, 1);
	}
}
