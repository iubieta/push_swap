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
	int	i;

	i = 0;
	if (ft_sorted(*stack_A))
		return ;
	if (ft_list_len(*stack_A) == 2 && ft_sorted(*stack_A) == 0)
	{
		ft_swap_head(stack_A);
		ft_printf("sa\n");
		return ;
	}
	while (ft_list_len(*stack_A) > 3 && i++ < 2)
	{
		ft_push_between(stack_A, stack_B);
		ft_printf("pb\n");
	}
	if (*stack_B != NULL && ft_list_len(*stack_A) > 3)
		ft_sort_b(stack_A, stack_B);
	if (ft_list_len(*stack_A) == 3)
		ft_sort_three(stack_A);
	if (*stack_B != NULL && ft_list_len(*stack_A) == 3)
		ft_push_b(stack_A, stack_B);
	if (ft_sorted(*stack_A) == 0)
		ft_lowest_at_top(stack_A);
}

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

//Checkea si la posicion a la que va a pushear el numero de B es correcta
//Sino, rota A hasta que lo sea
void	ft_push_b(t_list **stack_A, t_list **stack_B)
{
	int	i;
	int	len;
	int	place;

	i = 0;
	len = ft_list_len(*stack_B);
	while (i < len)
	{
		place = ft_find_place(*stack_A, (*stack_B)->content, 'a');
		if ((*stack_A)->content == place)
		{
			ft_push_between(stack_B, stack_A);
			ft_printf("pa\n");
			i++;
		}
		else
			ft_num_at_top(stack_A, place);
	}
}
