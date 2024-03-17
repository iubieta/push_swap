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

#include "push_swap.h"

int	ft_moves(t_list *head_A, t_list *head_B, int number)
{
	//Trabajar con una copia de los stacks
	int moves;
	int	a_moves;
	int b_moves;

}

int	ft_moves_to_top(t_list *head, int number)
{
	int moves_up;
	int	moves_down;
	int	min_moves;

	moves_up = ft_moves_up(head, number);
	moves_down = ft_moves_down(head, number);
	if (moves_up < moves_down)
		min_moves = moves_up;
	else
		min_moves = moves_down;
	return (min_moves);
}

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
		return(-1);
	return (moves);
}

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
		return(-1);
	return (ft_list_len - moves);
}



