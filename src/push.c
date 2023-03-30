/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:07:28 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/27 16:59:43 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stacks *stack, int to_print)
{
	int	tmp;

	if (stack->b[0] != -1)
	{
		tmp = stack->b[0];
		move_down(stack->a, stack->size);
		stack->a[0] = tmp;
		move_up(stack->b, stack->size);
		if (to_print == 1)
			ft_printf("pa\n");
	}
}

void	push_b(t_stacks *stack, int to_print)
{
	int	tmp;

	tmp = stack->a[0];
	if (stack->b[0] != -1)
		move_down(stack->b, stack->size);
	stack->b[0] = tmp;
	move_up(stack->a, stack->size);
	if (to_print == 1)
		ft_printf("pb\n");
}
