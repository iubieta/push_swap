/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:18:47 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/16 16:18:47 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Calculo del numero de movimientos necesarios por cada combinacion
//para colocar los stacks en posiciones correctas para ser pusheados
int	ft_aup_bup(t_list *head_A, t_list *head_B, int a, int b)
{
	int	a_moves;
	int	b_moves;

	a_moves = ft_moves_up(head_A, a);
	b_moves = ft_moves_up(head_B, b);
	if (a_moves > b_moves)
		return (a_moves);
	else
		return (b_moves);
}

int	ft_adown_bdown(t_list *head_A, t_list *head_B, int a, int b)
{
	int	a_moves;
	int	b_moves;

	a_moves = ft_moves_down(head_A, a);
	b_moves = ft_moves_down(head_B, b);
	if (a_moves > b_moves)
		return (a_moves);
	else
		return (b_moves);
}

int	ft_aup_bdown(t_list *head_A, t_list *head_B, int a, int b)
{
	int	moves;

	moves = ft_moves_up(head_A, a);
	moves += ft_moves_down(head_B, b);
	return (moves);
}

int	ft_adown_bup(t_list *head_A, t_list *head_B, int a, int b)
{
	int	moves;

	moves = ft_moves_down(head_A, a);
	moves += ft_moves_up(head_B, b);
	return (moves);
}
