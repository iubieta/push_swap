/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:18:27 by marvin            #+#    #+#             */
/*   Updated: 2024/04/08 20:18:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	stack_a = &head_a;
	stack_b = &head_b;
	if (ft_check_errors(argc, argv, stack_b) == 0)
		return (0);
	while (head_b != NULL)
		ft_push_between(stack_b, stack_a);
	ft_mechanical_turk(stack_a, stack_b);
	return (1);
}
