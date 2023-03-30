/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:26:30 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/29 13:39:29 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	fill_a(t_stacks *stack, char **matrix, char *str)
{
	int	i;

	i = -1;
	stack->a = (int *)ft_calloc(sizeof(int), stack->size);
	if (!stack->a || !str[0])
		error(stack->a);
	i = -1;
	while (++i < stack->size)
	{
		stack->a[i] = int_check(matrix[i], stack->a);
		non_repeat(stack->a, stack->a[i], i);
	}
}

static void	get_index(int *stack, t_order *order, int size)
{
	if (stack[++order->i] < order->to_take && order->tmp[order->i] == -1)
	{
		order->to_take = stack[order->i];
		order->pos = order->i;
	}
	if (order->i + 1 == size)
	{
		order->tmp[order->pos] = order->counter++;
		while (order->i >= 0)
		{
			if (stack[order->i] > order->to_take && order->tmp[order->i] == -1)
			{
			order->to_take = stack[order->i];
			order->pos = order->i;
			}
			order->i--;
		}
	}
}

static int	*pos_taker(int *stack, int size)
{
	t_order	order;

	order.tmp = ft_bnegative(size);
	order.to_take = stack[0];
	order.counter = 0;
	order.pos = 0;
	order.i = -1;
	while (order.counter < size)
	{
		get_index(stack, &order, size);
	}
	free(stack);
	return (order.tmp);
}

int	main(int argc, char **argv)
{
	t_stacks	stack;
	int			i;

	if (argc == 1)
		return (0);
	if (ft_strchr(argv[1], ' '))
	{
		stack.collector = ft_split(argv[1], ' ');
		i = 0;
		while (stack.collector[i])
			i++;
		stack.size = i;
		fill_a(&stack, stack.collector, argv[1]);
		free_matrix(stack.collector);
	}
	else
	{
		stack.size = argc - 1;
		fill_a(&stack, &argv[1], argv[1]);
	}
	stack.a = pos_taker(stack.a, stack.size);
	stack.b = ft_bnegative(stack.size);
	radix_sort(&stack);
}
