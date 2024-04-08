/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:17:47 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/16 17:17:47 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Ordena cualquier lista de 3 numeros
void	ft_sort_three(t_list **list)
{
	if (ft_sorted(*list))
		return ;
	if (ft_list_min(*list) == (*list)->content)
		ft_case_min_at_top(list);
	else if (ft_list_max(*list) == (*list)->content)
		ft_case_max_at_top(list);
	else
	{
		if ((*list)->content > ((*list)->next)->content)
		{
			ft_swap_head(list);
			ft_printf("sa\n");
		}
		else
		{
			ft_rotate_down(list);
			ft_printf("rra\n");
		}
	}
}

//Cuando el minimo esta arriba
void	ft_case_min_at_top(t_list **list)
{
	ft_swap_head(list);
	ft_printf("sa\n");
	ft_rotate_up(list);
	ft_printf("ra\n");
}

//Cuando el maximo esta arriba
void	ft_case_max_at_top(t_list **list)
{
	ft_rotate_up(list);
	ft_printf("ra\n");
	if (ft_sorted(*list) == 0)
	{
		ft_swap_head(list);
		ft_printf("sa\n");
	}
}

//Comprueba que la lista esta ordenada
int	ft_sorted(t_list *head)
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
