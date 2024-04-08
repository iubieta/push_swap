/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c 		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:18:47 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/16 16:18:47 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Busca el numero dentro de A que requiere menos movimientos 
//para pasarlo a B en la posicion correcta
int	ft_fastest_number(t_list *head_A, t_list *head_B)
{
	t_list	*node;
	int		number;
	int		fastest;
	int		moves;
	int		min_moves;

	node = head_A;
	fastest = node->content;
	min_moves = INT_MAX;
	while (node != NULL)
	{
		number = node->content;
		moves = ft_moves(head_A, head_B, number);
		if (moves < min_moves)
		{
			min_moves = moves;
			fastest = number;
		}
		node = node->next;
		if (moves == 0)
			return (fastest);
	}
	return (fastest);
}

//Busca la combinacion de movimientos idonea para pasar un numero especifico
//Imprime los movimientos, los ejecuta, imprimer el push y lo ejecuta
void	ft_sort_num(t_list **stack_A, t_list **stack_B, int number, char order)
{
	int	a;
	int	b;

	a = number;
	b = ft_find_place(*stack_B, a, order);
	ft_print_move(*stack_A, *stack_B, a, b);
	ft_apply_move(stack_A, stack_B, a, b);
}

//Busca el numero que tiene que quedar debajo del numero que se quiere pushear
//En orden ascendente --> el menor, mayor que el numero a pushear
//En orden descendent --> el mayor. menor que el numero a pushear
int	ft_find_place(t_list *head, int number, char order)
{
	t_list	*node;
	int		number_below;

	number_below = ft_check_place(head, number, order);
	node = head;
	while (node != NULL)
	{
		if (order == 'a' && node->content > number
			&& node->content < number_below)
			number_below = node->content;
		else if (order == 'd' && node->content < number
			&& node->content > number_below)
			number_below = node->content;
		node = node->next;
	}
	return (number_below);
}

//Comprueba si el numero a pushear seria un maximo o un minimo
//En esos casos el numero en la cabeza de B deberia ser el limite contrario
int	ft_check_place(t_list *head, int number, char order)
{
	int	max;
	int	min;

	max = ft_list_max(head);
	min = ft_list_min(head);
	if (order == 'a')
	{
		if (max < number)
			return (min);
		else
			return (max);
	}
	else
	{
		if (min > number)
			return (max);
		else
			return (min);
	}
}

//Busca la combinacion idonea para pasar un numero concreto de A a B
int	ft_get_move(t_list *head_A, t_list *head_B, int a, int b)
{
	int	moves[4];
	int	move;

	moves[0] = ft_aup_bup(head_A, head_B, a, b);
	moves[1] = ft_adown_bdown(head_A, head_B, a, b);
	moves[2] = ft_aup_bdown(head_A, head_B, a, b);
	moves[3] = ft_adown_bup(head_A, head_B, a, b);
	move = ft_min_index(moves);
	return (move);
}
