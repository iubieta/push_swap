#include "push_swap.h"

int ft_checkErrors(int argc, char **argv, int_list **stack)
{
	int     	i;
	int			num;
	char    	*argument;
	char    	*element;
	
	if (argc == 1)
	{
		printf("ERROR(0): No hay argumentos\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		argument = argv[i];
		printf("Argumento %i: %s\n",i,argument);
		if (ft_isalnum(argument[0]) == 1 || argument[0] == '-' || argument[0] == '+')
			element = argument;
		else
			element = ft_nextElement(argument);
		printf("Elemento: %s\n", element);
		while (element)
		{
			if(ft_checkPush(element, stack) == 0)
				return(0);
			element = ft_nextElement(element);
			printf("Elemento: %s\n", element);
		}
		i++;
	}
}

char	*ft_nextElement(char *element)
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

// Checkear string, checkear num=int, checkear num no repetido
int	ft_checkPush(char *element, int_list **stack)
{
	long		number;
	int_list	*node;

	if (ft_checkElement(element) == 0)
	{
		printf("ERROR (1): fallo en el string\n");
		return(0);
	}
	number = ft_atol(element);
	if (number < INT_MIN || number > INT_MAX)
	{
		printf("ERROR (2): numero no entero\n");
		return(0);
	}
	if (ft_existsInList((int)number, *stack) == 1)
	{
		printf("ERROR (3): numero repetido\n");
		return(0);
	}
	node = ft_lst_newNode((int)number);
	printf("New node: %i\n", node->content);
	ft_lst_addFront(stack, node);
	return(1);
}

int ft_checkElement(char *element)
{
	int i;
	
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