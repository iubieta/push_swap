/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:09:05 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/10 20:09:05 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Crea un nodo de tipo t_list
t_list	*ft_lst_new_node(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

//Añade un nodo al principio de la lista
void	ft_lst_add_front(t_list **list, t_list *node)
{
	if (node != NULL)
	{
		node->next = *list;
		*list = node;
	}
}

//Libera los nodos de la lista y los asigna a NULL
void	ft_free_list(t_list **list)
{
	t_list	*node;
	t_list	*reference;

	node = *list;
	while (node != NULL)
	{
		reference = node;
		node = node->next;
		free(reference);
		reference = NULL;
	}
	*list = NULL;
}

//Comprueba si un numero existe en la lista
int	ft_exists_in_list(int number, t_list *head)
{
	t_list	*current_node;

	current_node = head;
	while (current_node != NULL)
	{
		if (current_node->content == number)
			return (1);
		current_node = current_node->next;
	}
	return (0);
}

/* 
//Imprime una lista
void	ft_print_list(t_list *head)
{
	t_list	*node;

	node = head;
	while (node != NULL)
	{
		ft_printf("%i\n", node->content);
		node = node->next;
	}
}

//Imprime 2 listas en paralelo
void	ft_print_2list(t_list *head_a, t_list *head_b)
{
	t_list	*node_a;
	t_list	*node_b;

	node_a = head_a;
	node_b = head_b;
	while (node_a || node_b)
	{
		if (node_a)
		{
			ft_printf("%i\t", node_a->content);
			node_a = node_a->next;
		}
		else
			ft_printf("\t");
		if (node_b)
		{
			ft_printf("%i\n", node_b->content);
			node_b = node_b->next;
		}
		else
			ft_printf("\n");
	}
} 
*/
