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

	//INIT B
	ft_push_between(stack_A, stack_B);
	ft_push_between(stack_A, stack_B);
	
	//SORT B
	i = 0;
	len = ft_list_len(*stack_A);
	while (i < len - 3)
	{
		fastest_number = ft_fastest_number(*stack_A, *stack_B);
		ft_sort_number(stack_A, stack_B, fastest_number, 'd');
		ft_push_between(stack_A, stack_B);
		ft_printf("pb\n");
		i++;
	}
	
	//SORT THREE
	ft_sort_three(stack_A);
	
	//HIGHEST AT TOP
	ft_rotate_down(stack_A);
	
	//PUSH B
	i = 0;
	len = ft_list_len(*stack_B);
	while (i++ < len)
	{
		ft_sort_number(stack_B, stack_A, (*stack_B)->content, 'a');
		ft_push_between(stack_B, stack_A);
		ft_printf("pa\n");
	}
}
