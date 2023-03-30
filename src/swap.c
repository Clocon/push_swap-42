/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:57:37 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/29 13:41:17 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(int *stack, int to_print)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	if (to_print == 1)
		ft_printf("sa\n");
}

void	swap_b(int *stack, int to_print)
{
	swap_a(stack, 0);
	if (to_print == 1)
		ft_printf("sb\n");
}

void	swap_ab(t_stacks *stack, int to_print)
{
	swap_a(stack->a, 0);
	swap_a(stack->b, 0);
	if (to_print == 1)
		ft_printf("ss\n");
}
