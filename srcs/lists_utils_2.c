/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:17:47 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/16 17:17:47 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//pushea un nodo de una lista a otra 
void	ft_push_between(t_list **origin, t_list **destiny)
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

//Calcula la longitud de la lista
int	ft_list_len(t_list *head)
{
	int		len;
	t_list	*node;

	len = 0;
	node = head;
	while (node != NULL)
	{
		len++;
		node = node->next;
	}
	return (len);
}

//Devuelve el numero mas pequeño de una lista
int	ft_list_min(t_list *head)
{
	int		min;
	t_list	*node;

	if (head == NULL)
		return (INT_MAX);
	min = head->content;
	node = head;
	while (node != NULL)
	{
		if (node->content < min)
			min = node->content;
		node = node->next;
	}
	return (min);
}

//Devuelve el numero mas grande de una lista
int	ft_list_max(t_list *head)
{
	int		max;
	t_list	*node;

	if (head == NULL)
		return (INT_MIN);
	max = head->content;
	node = head;
	while (node != NULL)
	{
		if (node->content > max)
			max = node->content;
		node = node->next;
	}
	return (max);
}
