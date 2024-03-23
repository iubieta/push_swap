/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:20:41 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/20 19:20:41 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_move(int move, t_list *head_A, t_list *head_B, int a, int b)
{
	if (move == 0)
		ft_print_upup(head_A, head_B, a, b);
	if (move == 1)
		ft_print_downdown(head_A, head_B, a, b);
	if (move == 2)
		ft_print_updown(head_A, head_B, a, b);
	if (move == 3)
		ft_print_downup(head_A, head_B, a, b);
}

void	ft_print_upup(t_list *head_A, t_list *head_B, int a, int b)
{
	int i;
	int	a_moves;
	int	b_moves;

	i = 0;
	a_moves = ft_moves_up(head_A, a);
	b_moves = ft_moves_up(head_B, b);
	if (a_moves > b_moves)
	{
		while (i++ < b_moves)
			ft_printf("rr\n");
		while (i++ < a_moves);
			ft_printf("ra\n");
	}
	else
	{
		while (i++ < a_moves)
			ft_printf("rr\n");
		while (i++ < b_moves);
			ft_printf("rb\n");
	}
}

void	ft_print_downdown(t_list *head_A, t_list *head_B, int a, int b)
{
	int i;
	int	a_moves;
	int	b_moves;

	i = 0;
	a_moves = ft_moves_down(head_A, a);
	b_moves = ft_moves_down(head_B, b);
	if (a_moves > b_moves)
	{
		while (i++ < b_moves)
			ft_printf("rrr\n");
		while (i++ < a_moves);
			ft_printf("rra\n");
	}
	else
	{
		while (i++ < a_moves)
			ft_printf("rrr\n");
		while (i++ < b_moves);
			ft_printf("rrb\n");
	}
}

void	ft_print_updown(t_list *head_A, t_list *head_B, int a, int b)
{
	int	i;
	int	moves;

	i = 0;
	moves = ft_moves_up(head_A, a);
	while (i++ < moves)
		ft_printf("ra\n");
	moves += ft_moves_down(head_B, b);
	while (i++ < moves)
		ft_printf("rrb\n");
}

void	ft_print_downup(t_list *head_A, t_list *head_B, int a, int b)
{
	int	i;
	int	moves;

	i = 0;
	moves = ft_moves_down(head_A, a);
	while (i++ < moves)
		ft_printf("rra\n");
	moves += ft_moves_up(head_B, b);
	while (i++ < moves)
		ft_printf("rb\n");
}
