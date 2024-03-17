/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:17:47 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/16 17:17:47 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **list)
{
	if (ft_list_min(*list) == (*list)->content)
	{
		ft_swap_head(list);
		ft_rotate_up(list);
	}
	else if (ft_list_max(*list) == (*list)->content)
	{
		ft_rotate_up(list);
		if (ft_sorted(*list) == 0)
			ft_swap_head(list);
	}
	else
	{
		if ((*list)->content > ((*list)->next)->content)
			ft_swap_head(list);
		else
			ft_rotate_down(list);
	}
}

int ft_sorted(t_list *head)
{
	t_list	*node;


	node = head;
	while (node->next != NULL)
	{
		if (node->content < (node->next)->content)
			node = node->next;
		else
			return (0);
	}
	return (1);
}
