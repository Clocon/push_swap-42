/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:18:41 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/29 13:41:02 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_up(int *stack, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		stack[i] = stack[i + 1];
		if (i + 2 == size)
		{
			i++;
			stack[i] = -1;
		}
	}
}

void	move_down(int *stack, int size)
{
	int	i;

	i = size - 1;
	while (--i >= 0)
		stack[i + 1] = stack[i];
	stack[0] = -1;
}
