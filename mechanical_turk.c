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

void	ft_mechanical_turk(t_list **stack_A, t_list stack_B)
{
	int	i;
	int	fastest_number;
	
	ft_push_between(stack_A, stack_B);
	ft_push_between(stack_A, stack_B);
	i = 0;
	while (i < ft_list_len(*stack_A) - 3)
	{
		fastest_number = ft_fastest_number(stack_A, stack_B);
		ft_sort_number(stack_A, stack_B, fastest_number);
		i++;
	}
	ft_sort_up(stack_A);
	ft_rotate_down(stack_A);
	i = 0;
	while (i < ft_listlen(stack_B))
	{
		if  (ft_list_min(*stack_A) < (*stack_B)->content)
			ft_push_between(stack_B,stack_A);
		else
			ft_sort_up(stack_A);
	}
	ft_sort_up(stack_A);
}