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
# include "./libft/libft.h"

typedef struct int_list
{
	int	content;
	struct int_list *next;
} int_list;

int 	ft_checkErrors(int argc, char **argv, int_list **stack);
char	*ft_nextElement(char *element);
int 	ft_checkElement(char *element);
size_t	ft_strlen(const char *s);
void	ft_pushNumber(char *element, int_list **stack);

# endif