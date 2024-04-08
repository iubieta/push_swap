/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:18:47 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/16 16:18:47 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Calcula el numero de movimientos necesarios para
//pasar un numero a B en la posicion correcta
int	ft_moves(t_list *head_A, t_list *head_B, int number)
{
	int	a;
	int	b;
	int	moves[4];
	int	min_moves;
	int	i;

	a = number;
	b = ft_find_place(head_B, a, 'd');
	moves[0] = ft_aup_bup(head_A, head_B, a, b);
	moves[1] = ft_adown_bdown(head_A, head_B, a, b);
	moves[2] = ft_aup_bdown(head_A, head_B, a, b);
	moves[3] = ft_adown_bup(head_A, head_B, a, b);
	min_moves = moves[0];
	i = 0;
	while (i < 4)
	{
		if (moves[i] < min_moves)
			min_moves = moves[i];
		i++;
	}
	return (min_moves);
}

//Calcula el n de rotaciones hacia arriba para colocar un numero en top
int	ft_moves_up(t_list *head, int number)
{
	t_list	*node;
	int		moves;

	node = head;
	moves = 0;
	while (node->content != number && node != NULL)
	{
		moves++;
		node = node->next;
	}
	if (node == NULL)
		return (-1);
	return (moves);
}

//Calcula el n de rotaciones hacia abajo para colocar un numero en top
int	ft_moves_down(t_list *head, int number)
{
	t_list	*node;
	int		moves;

	node = head;
	moves = 0;
	while (node->content != number && node != NULL)
	{
		moves++;
		node = node->next;
	}
	if (node == NULL)
		return (-1);
	return (ft_list_len(head) - moves);
}
