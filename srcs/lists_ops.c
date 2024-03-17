/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:40:54 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/11 19:40:54 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//intercambia los dos primeros nodos
void	ft_swap_head(t_list **list)
{
	t_list	*head;
	t_list	*next;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	head = *list;
	next = head->next;
	head->next = next->next;
	next->next = head;
	*list = next;
}

//pushea un nodo de una lista a otra 
void	ft_push_between_lists(t_list **origin, t_list **destiny)
{
	t_list	*origin_head;
	t_list	*del;

	if (*origin == NULL )
		return ;
	origin_head = *origin;
	*origin = origin_head->next;
	origin_head->next = *destiny;
	*destiny = origin_head;
}

//rota la lista hacia arriba
void	ft_rotate_up(t_list **list)
{
	t_list	*head;
	t_list	*node;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	head = *list;
	*list = head->next;
	node = *list;
	while (node->next != NULL)
		node = node->next;
	node->next = head;
	head->next = NULL;
}

//rota la lista hacia abajo
void	ft_rotate_down(t_list **list)
{
	t_list	*prev;
	t_list	*last;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	prev = NULL;
	last = *list;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *list;
	*list = last;
}
