/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:20:41 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/20 19:20:41 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Ejecuta la combinacion de movimientos indicada 
//hasta que ambos numeros queden en la cabeza de sus respectivas listas
void	ft_apply_move(int move, t_list **stack_A, t_list **stack_B, int a, int b)
{
	if (move == 0)
		ft_apply_upup(stack_A, stack_B, a, b);
	if (move == 1)
		ft_apply_downdown(stack_A, stack_B, a, b);
	if (move == 2)
		ft_apply_updown(stack_A, stack_B, a, b);
	if (move == 3)
		ft_apply_downup(stack_A, stack_B, a, b);
}

//
void	ft_apply_upup(t_list **stack_A, t_list **stack_B, int a, int b)
{
	int i;
	int	a_moves;
	int	b_moves;

	i = 0;
	a_moves = ft_moves_up(*stack_A, a);
	b_moves = ft_moves_up(*stack_B, b);
	if (a_moves >= b_moves)
	{
		while (i++ < b_moves)
			ft_rotate_both_up(stack_A, stack_B);
		while (i++ < a_moves + 1)
			ft_rotate_up(stack_A);
	}
	else
	{
		while (i++ < a_moves)
			ft_rotate_both_up(stack_A, stack_B);
		while (i++ < b_moves + 1)
			ft_rotate_up(stack_B);
	}
}

void	ft_apply_downdown(t_list **stack_A, t_list **stack_B, int a, int b)
{
	int i;
	int	a_moves;
	int	b_moves;

	i = 0;
	a_moves = ft_moves_down(*stack_A, a);
	b_moves = ft_moves_down(*stack_B, b);
	if (a_moves >= b_moves)
	{
		while (i++ < b_moves)
			ft_rotate_both_down(stack_A, stack_B);
		while (i++ < a_moves + 1)
			ft_rotate_down(stack_A);
	}
	else
	{
		while (i++ < a_moves)
			ft_rotate_both_down(stack_A, stack_B);
		while (i++ < b_moves + 1)
			ft_printf("rb\n");
	}
}

void	ft_apply_updown(t_list **stack_A, t_list **stack_B, int a, int b)
{
	int	i;
	int	moves;

	i = 0;
	moves = ft_moves_up(*stack_A, a);
	while (i++ < moves)
		ft_rotate_up(stack_A);
	moves += ft_moves_down(*stack_B, b);
	while (i++ < moves + 1)
		ft_rotate_down(stack_B);
}

void	ft_apply_downup(t_list **stack_A, t_list **stack_B, int a, int b)
{
	int	i;
	int	moves;

	i = 0;
	moves = ft_moves_down(*stack_A, a);
	while (i++ < moves)
		ft_rotate_down(stack_A);
	moves += ft_moves_up(*stack_B, b);
	while (i++ < moves + 1)
		ft_rotate_up(stack_B);
}
