/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:06:41 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/24 13:04:52 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(int *stack, int size, int to_print)
{
	int	tmp;
	int	i;

	tmp = stack[0];
	move_up(stack, size);
	i = -1;
	while (++i < size)
	{
		if (stack[i] == -1)
		{
			stack[i] = tmp;
			break ;
		}
	}
	if (to_print == 1)
		ft_printf("ra\n");
}

void	rotate_b(int *stack, int size, int to_print)
{
	rotate_a(stack, size, 0);
	if (to_print == 1)
		ft_printf("rb\n");
}

void	rotate_ab(t_stacks *stack, int to_print)
{
	rotate_a(stack->a, stack->size, 0);
	rotate_a(stack->b, stack->size, 0);
	if (to_print == 1)
		ft_printf("rr\n");
}
