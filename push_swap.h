/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:57:40 by iubieta-          #+#    #+#             */
/*   Updated: 2024/02/19 19:30:42 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct int_list
{
	int	content;
	struct int_list *next;
} int_list;

int 		ft_checkErrors(int argc, char **argv, int_list **stack);
char		*ft_nextElement(char *element);
int			ft_checkPush(char *element, int_list **stack);
int 		ft_checkElement(char *element);
long		ft_atol(const char *s);
int_list 	*ft_lst_newNode(int content);
void		ft_lst_addFront(int_list **list, int_list *node);
void		ft_printList(int_list **list);
int			ft_existsInList(int number, int_list **stack);

# endif