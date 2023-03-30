/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:55:14 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/29 13:58:07 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	five(t_stacks *stack, int to_check)
{
	int	i;

	i = -1;
	while (++i < stack->size)
	{
		if (stack->a[i] == to_check)
			break ;
	}
	if (i == 2)
	{
		rotate_a(stack->a, stack->size, 1);
		i--;
	}
	if (i == 1)
		rotate_a(stack->a, stack->size, 1);
	if (i == 3)
	{
		reverse_a(stack->a, stack->size, 1);
		reverse_a(stack->a, stack->size, 1);
	}
	if (i == 4)
		reverse_a(stack->a, stack->size, 1);
	push_b(stack, 1);
	stack->size--;
	four(stack, 1);
}

void	four(t_stacks *stack, int to_check)
{
	int	i;

	i = -1;
	while (++i < stack->size)
	{
		if (stack->a[i] == to_check)
			break ;
	}
	if (i == 2)
	{
		rotate_a(stack->a, stack->size, 1);
		i--;
	}
	if (i == 1)
		rotate_a(stack->a, stack->size, 1);
	if (i == 3)
		reverse_a(stack->a, stack->size, 1);
	push_b(stack, 1);
	stack->size--;
}

void	three(t_stacks *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2])
		rotate_a(stack->a, stack->size, 1);
	else if (stack->a[1] > stack->a[2])
		reverse_a(stack->a, stack->size, 1);
	stack->size--;
}

void	two(t_stacks *stack)
{
	if (stack->a[0] > stack->a[1])
		swap_a(stack->a, 1);
}
