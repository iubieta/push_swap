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

#include "push_swap.h"

void	ft_apply_move(int move, t_list **stack_A, t_list **stack_B, int number)
{
	int	a;
	int b;

	a = number;
	b = ft_find_place(head_B, a);
	if (move == 0)
		ft_apply_upup(stack_A, stack_B, a, b);
	if (move == 1)
		ft_apply_downdown(stack_A, stack_B, a, b);
	if (move == 2)
		ft_apply_updown(stack_A, stack_B, a, b);
	if (move == 3)
		ft_apply_downup(stack_A, stack_B, a, b);
}

void	ft_apply_upup(t_list **stack_A, t_list **stack_B, int a, int b)
{
	int i;
	int	a_moves;
	int	b_moves;

	i = 0;
	a_moves = ft_moves_up(*stack_A, a);
	b_moves = ft_moves_up(*stack_B, b);
	if (a_moves > b_moves)
	{
		while (i++ < b_moves)
			ft_rotate_up(stack_A);
		while (i++ < a_moves);
			ft_applyf("rra\n");
	}
	else
	{
		while (i++ < a_moves)
			ft_applyf("rr\n");
		while (i++ < b_moves);
			ft_applyf("rrb\n");
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
	if (a_moves > b_moves)
	{
		while (i++ < b_moves)
			ft_applyf("rrr\n");
		while (i++ < a_moves);
			ft_applyf("ra\n");
	}
	else
	{
		while (i++ < a_moves)
			ft_applyf("rrr\n");
		while (i++ < b_moves);
			ft_applyf("rb\n");
	}
}

void	ft_apply_updown(t_list **stack_A, t_list **stack_B, int a, int b)
{
	int	i;
	int	moves;

	i = 0;
	moves = ft_moves_up(*stack_A, a);
	while (i++ < moves)
		ft_applyf("ra\n");
	moves += ft_moves_down(*stack_B, b);
	while (i++ < moves)
		ft_applyf("rrb\n");
}

void	ft_apply_downup(t_list **stack_A, t_list **stack_B, int a, int b)
{
	int	i;
	int	moves;

	i = 0;
	moves = ft_moves_down(*stack_A, a);
	while (i++ < moves)
		ft_applyf("rra\n");
	moves += ft_moves_up(*stack_B, b);
	while (i++ < moves)
		ft_applyf("rb\n");
}
