/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:18:28 by marvin            #+#    #+#             */
/*   Updated: 2024/03/11 14:18:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap_head(t_list **list)
{
	t_list	*head;
	t_list	*next;

	if (*list == NULL || *list->next == NULL)
		return;
	head = *list;
	next = head->next;
	head->next = next->next;
	next->next = head;
	*list = next;
}

void ft_push_between_lists(t_list **origin, t_list **destiny)
{
	t_list	*origin_head;
	
	if (*origin == NULL)
		return;
	origin_head = *origin;
	if (origin_head->next != NULL)
		*origin = origin_head->next;
	origin_head->next = *destiny;
	*destiny = origin_head;
}

void ft_rotate_up(t_list **list)
{
	t_list	*head;
	t_list	*node;

	if (*list == NULL)
		return;
	head = *list;
	while (node != NULL)
	{
		/* code */
	}
	
}
