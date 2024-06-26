/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:08:07 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/10 20:08:07 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//pasa un string a tipo long
long	ft_atol(const char *s)
{
	size_t			i;
	unsigned long	number;
	int				sign;

	i = 0;
	sign = 1;
	number = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\r' || s[i] == '\v' || s[i] == '\f' )
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		number = number * 10 + s[i] - 48;
		i++;
	}
	i++;
	return (number * sign);
}

//Busca la posicion de el menor dentro de un array
int	ft_min_index(int *array)
{
	int	i;
	int	min;
	int	index;

	min = array[0];
	index = 0;
	i = 1;
	while (i < 4)
	{
		if (min > array[i])
		{
			min = array[i];
			index = i;
		}
		i++;
	}
	return (index);
}
