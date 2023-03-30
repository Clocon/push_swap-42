/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:16:13 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/29 11:19:01 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	non_repeat(int *stack, int nb, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (stack[i] == nb)
			error(stack);
	}
}

int	int_check(char *str, int *stack)
{
	long	nb;
	int		i;

	i = -1;
	if (str[0] == '-' && (str[1] < '0' || str[1] > '9'))
		error(stack);
	else if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == 0)
			error(stack);
	}
	nb = ft_atoi_long(str);
	if (nb > INT_MAX || nb < INT_MIN)
		error(stack);
	return (nb);
}
