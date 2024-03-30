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

#include "../include/push_swap.h"

//Algoritmo para buscar la forma optima de ordenamiento
void	ft_mechanical_turk(t_list **stack_A, t_list **stack_B)
{
	ft_push_between(stack_A, stack_B);
	ft_printf("pb\n");
	ft_push_between(stack_A, stack_B);
	ft_printf("pb\n");
	ft_sort_b(stack_A, stack_B);
	ft_sort_three(stack_A);
	ft_highest_at_top(stack_B);
	ft_push_b(stack_A, stack_B);
}
	/*
	faltaria ver si es necesario rotar A hasta que el minimo este en el top
	y comprobar si la lista esta ordenada
	*/

//Pushea los numeros de A a B de forma ordenada
void	ft_sort_b(t_list **stack_A, t_list **stack_B)
{
	int	i;
	int	len;
	int	fastest_number;

	i = 0;
	len = ft_list_len(*stack_A);
	while (i < len - 3)
	{
		fastest_number = ft_fastest_number(*stack_A, *stack_B);
		ft_sort_num(stack_A, stack_B, fastest_number, 'd');
		ft_push_between(stack_A, stack_B);
		ft_printf("pb\n");
		i++;
	}
}

//Coloca el numero mas alto de B en el top
void	ft_highest_at_top(t_list **list)
{
	int	max;
	int	moves_up;
	int	moves_down;

	max = ft_list_max(*list);
	moves_up = ft_moves_up(*list, max);
	moves_down = ft_moves_down(*list, max);
	while ((*list)->content != max)
	{
		if (moves_up < moves_down)
		{
			ft_rotate_up(list);
			ft_printf("rb\n");
		}
		else
		{
			ft_rotate_down(list);
			ft_printf("rrb\n");
		}
	}
}

//Checkea si la posicion a la que va a pushear el numero de B es correcta
//Sino, rota A hasta que lo sea
void	ft_push_b(t_list **stack_A, t_list **stack_B)
{
	int	i;
	int	len;

	i = 0;
	len = ft_list_len(*stack_B);
	while (i < len)
	{
		if ((*stack_A)->content
			== ft_find_place(*stack_A, (*stack_B)->content, 'a'))
		{
			ft_push_between(stack_B, stack_A);
			ft_printf("pa\n");
			i++;
		}
		else
		{
			//ft_sort_num(stack_B, stack_A, (*stack_B)->content, 'd');
			ft_rotate_down(stack_A);
			ft_printf("rra\n");
		}
	}
}
