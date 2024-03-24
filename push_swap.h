/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:57:40 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/24 10:23:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "./srcs/libft/libft.h"
# include "./srcs/printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int		ft_check_errors(int argc, char **argv, t_list **stack);
char	*ft_first_element(char *argument);
char	*ft_next_element(char *element);
int		ft_check_push(char *element, t_list **stack);
int		ft_check_element(char *element);

long	ft_atol(const char *s);
int		ft_min_index(int *array);


t_list	*ft_lst_new_node(int content);
void	ft_lst_add_front(t_list **list, t_list *node);
void	ft_print_list(t_list *head);
void	ft_free_list(t_list **list);
int		ft_exists_in_list(int number, t_list *head);

void	ft_swap_head(t_list **list);
void	ft_push_between(t_list **origin, t_list **destiny);
void	ft_rotate_up(t_list **list);
void	ft_rotate_down(t_list **list);
void	ft_rotate_both_up(t_list **list_A, t_list **list_B);
void	ft_rotate_both_down(t_list **list_A, t_list **list_B);

int		ft_list_len(t_list *head);
int		ft_list_min(t_list *head);
int		ft_list_max(t_list *head);

void	ft_sort_three(t_list **list);
int		ft_sorted(t_list *head);

void	ft_mechanical_turk(t_list **stack_A, t_list **stack_B);
int		ft_fastest_number(t_list *head_A, t_list *head_B);
void	ft_sort_number(t_list **stack_A, t_list **stack_B, int number, char order);
int		ft_find_place(t_list *head, int number, char order);
int		ft_check_place(t_list *head, int number, char order);
int		ft_get_move(t_list *head_A, t_list *head_B, int a, int b);

int		ft_moves(t_list *head_A, t_list *head_B, int number);
int		ft_moves_up(t_list *head, int number);
int		ft_moves_down(t_list *head, int number);

int		ft_aup_bup(t_list *head_A, t_list *head_B, int a, int b);
int		ft_adown_bdown(t_list *head_A, t_list *head_B, int a, int b);
int		ft_aup_bdown(t_list *head_A, t_list *head_B, int a, int b);
int		ft_adown_bup(t_list *head_A, t_list *head_B, int a, int b);

void	ft_print_move(int move, t_list *head_A, t_list *head_B, int a, int b);
void	ft_print_upup(t_list *head_A, t_list *head_B, int a, int b);
void	ft_print_downdown(t_list *head_A, t_list *head_B, int a, int b);
void	ft_print_updown(t_list *head_A, t_list *head_B, int a, int b);
void	ft_print_downup(t_list *head_A, t_list *head_B, int a, int b);

void	ft_apply_move(int move, t_list **stack_A, t_list **stack_B, int a, int b);
void	ft_apply_upup(t_list **stack_A, t_list **stack_B, int a, int b);
void	ft_apply_downdown(t_list **stack_A, t_list **stack_B, int a, int b);
void	ft_apply_updown(t_list **stack_A, t_list **stack_B, int a, int b);
void	ft_apply_downup(t_list **stack_A, t_list **stack_B, int a, int b);

#endif