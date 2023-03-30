/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:06:08 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/28 17:30:49 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	arr_size(int *stack, int size)
{
	int	i;

	i = 0;
	while (stack[i] != -1 && i < size)
		i++;
	return (i);
}

static int	get_max_bits(t_stacks *stack)
{
	int	max_bits;
	int	nb;

	max_bits = 0;
	nb = stack->size;
	while (nb > 0)
	{
		nb /= 2;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_stacks *stack)
{
	int	max_bits;
	int	i;

	if (stack->size < 6)
		short_moves(stack);
	max_bits = get_max_bits(stack);
	i = -1;
	while (++i < max_bits)
	{
		if (is_completed(stack) == 1)
			break ;
		if (is_sorted(stack) == 0)
			move_a(stack, i);
		move_b(stack, max_bits, i);
	}
	free(stack->a);
	free(stack->b);
	exit (0);
}
