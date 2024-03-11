/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:57:40 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/11 14:52:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int			ft_check_errors(int argc, char **argv, t_list **stack);
char		*ft_first_element(char *argument);
char		*ft_next_element(char *element);
int			ft_check_push(char *element, t_list **stack);
int			ft_check_element(char *element);
long		ft_atol(const char *s);
t_list		*ft_lst_new_node(int content);
void		ft_lst_add_front(t_list **list, t_list *node);
void		ft_print_list(t_list *head);
void		ft_free_list(t_list **list);
int			ft_exists_in_list(int number, t_list *head);

#endif