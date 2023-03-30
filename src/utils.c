/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:08:03 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/29 13:41:30 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(int *for_free)
{
	ft_putstr_fd("Error\n", 2);
	free(for_free);
	exit(1);
}

void	free_matrix(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	*ft_bnegative(size_t n)
{
	size_t	i;
	int		*nb;

	nb = (int *) malloc(sizeof(int) * n);
	if (!nb)
		error(nb);
	i = 0;
	while (i < n)
	{
		nb[i] = -1;
		i++;
	}
	return (nb);
}

long	ft_atoi_long(char *nptr)
{
	int		i;
	long	pol;
	long	toint;

	i = 0;
	pol = 1;
	toint = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
		pol = -1;
	if (nptr[i] == '+' || pol == -1)
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		toint = toint * 10 + (nptr[i++] - 48);
	return (toint * pol);
}
