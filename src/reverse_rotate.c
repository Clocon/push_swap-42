/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:06:24 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/27 16:59:23 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_a(int *stack, int size, int to_print)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = -1;
	while (++i < size)
	{
		if (stack[i + 1] == -1 || i + 1 == size)
		{
			tmp = stack[i];
			break ;
		}
	}
	move_down(stack, size);
	stack[0] = tmp;
	if (to_print == 1)
		ft_printf("rra\n");
}

void	reverse_b(int *stack, int size, int to_print)
{
	reverse_a(stack, size, 0);
	if (to_print == 1)
		ft_printf("rrb\n");
}

void	reverse_ab(t_stacks *stack, int to_print)
{
	reverse_a(stack->a, stack->size, 0);
	reverse_a(stack->b, stack->size, 0);
	if (to_print == 1)
		ft_printf("rrr\n");
}
