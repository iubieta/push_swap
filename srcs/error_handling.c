/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:09:05 by iubieta-          #+#    #+#             */
/*   Updated: 2024/03/10 20:09:05 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Funcion principal para checkear los errores
int	ft_check_errors(int argc, char **argv, t_list **stack)
{
	int		i;
	int		num;
	char	*argument;
	char	*element;

	if (argc == 1)
	{
		ft_printf("ERROR(0): No hay argumentos\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		argument = argv[i++];
		element = ft_first_element(argument);
		while (element)
		{
			if (ft_check_push(element, stack) == 0)
				return (0);
			element = ft_next_element(element);
			//printf("Elemento: %s\n", element);
		}
	}
}

//Avanza hasta el primer elemento del argumento
char	*ft_first_element(char *argument)
{
	char	*element;

	if (ft_isalnum(argument[0]) == 1 || argument[0] == '-'
		|| argument[0] == '+')
		element = argument;
	else
		element = ft_next_element(argument);
	return (element);
}

//Avanza hasta el siguiente elemento del string
char	*ft_next_element(char *element)
{
	int	i;

	i = 0;
	if (element[0] == '-' || element[0] == '+')
		i++;
	while (ft_isalnum(element[i]) == 1)
	{
		if (ft_isdigit(element[i]))
			i++;
		else
			return (NULL);
	}
	while (element[i] == ' ' || element[i] == '\t' || element[i] == '\n'
		|| element[i] == '\r' || element[i] == '\v' || element[i] == '\f' )
		i++;
	if (element[i] == '\0')
		return (NULL);
	return (&element[i]);
}

// Checkea todos los posibles errores y si no los hay añade el numero al stack
int	ft_check_push(char *element, t_list **stack)
{
	long	number;
	t_list	*node;

	if (ft_check_element(element) == 0)
	{
		ft_printf("ERROR (1): fallo en el string\n");
		return (0);
	}
	number = ft_atol(element);
	if (number < INT_MIN || number > INT_MAX)
	{
		ft_printf("ERROR (2): numero no entero\n");
		return (0);
	}
	if (ft_exists_in_list((int)number, *stack) == 1)
	{
		ft_printf("ERROR (3): numero repetido\n");
		return (0);
	}
	node = ft_lst_new_node((int)number);
	//ft_printf("New node: %i\n", node->content);
	ft_lst_add_front(stack, node);
	return (1);
}

//Checkea el primer elemento del string
int	ft_check_element(char *element)
{
	int	i;

	i = 0;
	if (element[0] == '-' || element[0] == '+')
		i++;
	while (element[i] && ft_isalnum(element[i]))
	{
		if (ft_isdigit(element[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
