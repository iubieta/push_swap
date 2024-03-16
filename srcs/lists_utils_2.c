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

int ft_list_min(t_list *head)
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

int ft_list_max(t_list *head)
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