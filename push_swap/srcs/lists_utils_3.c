/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:15:33 by marvin            #+#    #+#             */
/*   Updated: 2024/04/08 20:15:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Coloca el numero mas alto de B en el top
void	ft_highest_at_top(t_list **list)
{
	int	max;
	int	moves_up;
	int	moves_down;

	max = ft_list_max(*list);
	moves_up = ft_moves_up(*list, max);
	moves_down = ft_moves_down(*list, max);
	while ((*list)->content != max)
	{
		if (moves_up < moves_down)
		{
			ft_rotate_up(list);
			ft_printf("rb\n");
		}
		else
		{
			ft_rotate_down(list);
			ft_printf("rrb\n");
		}
	}
}

//Coloca el numero mas bajo de A en el top
void	ft_lowest_at_top(t_list **list)
{
	int	min;
	int	moves_up;
	int	moves_down;

	min = ft_list_min(*list);
	moves_up = ft_moves_up(*list, min);
	moves_down = ft_moves_down(*list, min);
	while ((*list)->content != min)
	{
		if (moves_up < moves_down)
		{
			ft_rotate_up(list);
			ft_printf("ra\n");
		}
		else
		{
			ft_rotate_down(list);
			ft_printf("rra\n");
		}
	}
}

//Coloca el numero mas bajo de A en el top
void	ft_num_at_top(t_list **list, int number)
{
	int	moves_up;
	int	moves_down;

	moves_up = ft_moves_up(*list, number);
	moves_down = ft_moves_down(*list, number);
	while ((*list)->content != number)
	{
		if (moves_up < moves_down)
		{
			ft_rotate_up(list);
			ft_printf("ra\n");
		}
		else
		{
			ft_rotate_down(list);
			ft_printf("rra\n");
		}
	}
}
