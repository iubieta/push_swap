/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanical_turk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:18:47 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/16 16:18:47 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mechanical_turk(t_list **stack_A, t_list **stack_B)
{
	int	i;
	int len;
	int	fastest_number;

	ft_push_between(stack_A, stack_B);
	ft_push_between(stack_A, stack_B);
	printf("Stack A:\n");
	ft_print_list(*stack_A);
	printf("Stack B:\n");
	ft_print_list(*stack_B);
	printf("------------\n");
	
	//SORT B
	i = 0;
	len = ft_list_len(*stack_A);
	while (i < len - 3)
	{
		fastest_number = ft_fastest_number(*stack_A, *stack_B);
		ft_sort_number(stack_A, stack_B, fastest_number, 'b');
		ft_push_between(stack_A, stack_B);
		ft_printf("pb\n");
		i++;
	}
	printf("Sort B:\n");
	printf("------------\n");
	printf("Stack A:\n");
	ft_print_list(*stack_A);
	printf("Stack B:\n");
	ft_print_list(*stack_B);
	printf("------------\n");
	
	//SORT THREE
	ft_sort_three(stack_A);
	printf("Sort three:\n");
	printf("------------\n");
	printf("Stack A:\n");
	ft_print_list(*stack_A);
	printf("Stack B:\n");
	ft_print_list(*stack_B);
	printf("------------\n");
	
	//HIGHEST AT TOP
	ft_rotate_down(stack_A);
	printf("Highest at top:\n");
	printf("------------\n");
	printf("Stack A:\n");
	ft_print_list(*stack_A);
	printf("Stack B:\n");
	ft_print_list(*stack_B);
	printf("------------\n");
	
	//PUSH B
	i = 0;
	len = ft_list_len(*stack_B);
	while (i++ < len)
	{
		ft_sort_number(stack_B, stack_A, (*stack_B)->content, 'a');
		ft_push_between(stack_B, stack_A);
		ft_printf("pa\n");
	}
	printf("Sort A:\n");
	printf("------------\n");
	printf("Stack A:\n");
	ft_print_list(*stack_A);
	printf("Stack B:\n");
	ft_print_list(*stack_B);
	printf("------------\n");
}

//Busca el numero dentro de A que requiere menos movimientos 
//para pasarlo a B en la posicion correcta
int	ft_fastest_number(t_list *head_A, t_list *head_B)
{
	t_list	*node;
	int		number;
	int		fastest;
	int		moves;
	int		min_moves;

	//printf("ft_fastest_number\n");
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
	}
	return (fastest);
}

//Busca cual es la combinacion de movimientos idonea para pasar un numero especifico
//Imprime los movimientos, los ejecuta, imprimer el push y lo ejecuta
void	ft_sort_number(t_list **stack_A, t_list **stack_B, int number, char order)
{
	int a;
	int b;
	int	move;
	
	//printf("ft_sort_number\n");
	a = number;
	b = ft_find_place(*stack_B, a, order);
	move = ft_get_move(*stack_A, *stack_B, a, b);
	ft_print_move(move, *stack_A, *stack_B, a, b);
	ft_apply_move(move, stack_A, stack_B, a, b);
}

//Busca el numero que tiene que quedar debajo del numero que se quiere pushear
//En orden ascendente --> el menor, mayor que el numero a pushear
//En orden descendent --> el mayor. menor que el numero a pushear
int	ft_find_place(t_list *head, int number, char order)
{
	t_list	*node;
	int		number_below;
	
	//printf("ft_find_place\n");
	node = head;
	if (order == 'a')
		number_below = ft_list_max(head);
	else if (order == 'b')
		number_below = ft_list_min(head);
	while (node != NULL)
	{	
		if (order == 'a' && node->content > number && node->content < number_below)
			number_below = node->content;
		else if (order == 'b' && node->content < number && node->content > number_below)
			number_below = node->content;
		node = node->next;
	}
	return (number_below);
}

//Busca la combinacion de movimientos idonea para pasar un numero concreto de A a B
int	ft_get_move(t_list *head_A, t_list *head_B, int a, int b)
{
	int	moves[4];
	int	move;
	int	i;

	//printf("ft_get_move\n");
	moves[0] = ft_aup_bup(head_A, head_B, a, b);
	moves[1] = ft_adown_bdown(head_A, head_B, a, b);
	moves[2] = ft_aup_bdown(head_A, head_B, a, b);
	moves[3] = ft_adown_bdown(head_A, head_B, a, b);
	move = ft_min_index(moves);
	return (move);
}
