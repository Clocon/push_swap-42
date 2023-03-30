/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:51:53 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/30 13:20:38 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include <limits.h>

typedef struct s_order
{
	int		*tmp;
	int		i;
	int		pos;
	int		to_take;
	int		counter;
}	t_order;

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		size;
	char	**collector;
}	t_stacks;

/*Functions for utils.c*/
void	error(int *for_free);
void	free_matrix(char **str);
int		*ft_bnegative(size_t n);
long	ft_atoi_long(char *nptr);

/*Functions for args_checker.c*/
void	non_repeat(int *cont, int nb, int n);
int		int_check(char *str, int *stack);

/*Functions for push.c*/
void	push_a(t_stacks *stack, int to_print);
void	push_b(t_stacks *stack, int to_print);

/*Functions for rotate.c*/
void	rotate_a(int *stack, int size, int to_print);
void	rotate_b(int *stack, int size, int to_print);
void	rotate_ab(t_stacks *stack, int to_print);

/*Functions for reverse_rotate.c*/
void	reverse_a(int *stack, int size, int to_print);
void	reverse_b(int *stack, int size, int to_print);
void	reverse_ab(t_stacks *stack, int to_print);

/*Functions for swap.c*/
void	swap_a(int *stack, int to_print);
void	swap_b(int *stack, int to_print);
void	swap_ab(t_stacks *stack, int to_print);

/*Functions for move_arr.c*/
void	move_up(int *stack, int size);
void	move_down(int *stack, int size);

/*Functions for radix.c*/
void	radix_sort(t_stacks *stack);
int		arr_size(int *stack, int size);

/*Functions for few_arguments.c*/
void	five(t_stacks *stack, int to_check);
void	four(t_stacks *stack, int to_check);
void	three(t_stacks *stack);
void	two(t_stacks *stack);

/*Functions for game.c*/
void	short_moves(t_stacks *stack);
int		is_sorted(t_stacks *stack);
int		is_completed(t_stacks *stack);
void	move_a(t_stacks *stack, int n_bits);
void	move_b(t_stacks *stack, int max_bits, int n_bits);

#endif
