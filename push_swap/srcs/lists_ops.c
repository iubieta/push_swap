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

#include "../include/push_swap.h"

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

//rota ambas listas hacia arriba
void	ft_rotate_both_up(t_list **list_A, t_list **list_B)
{
	ft_rotate_up(list_A);
	ft_rotate_up(list_B);
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

//rota ambas listas hacia abajo
void	ft_rotate_both_down(t_list **list_A, t_list **list_B)
{
	ft_rotate_down(list_A);
	ft_rotate_down(list_B);
}
