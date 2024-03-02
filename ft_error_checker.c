#include "push_swap.h"

int ft_checkErrors(int argc, char **argv, int_list **stack)
{
	int     i;
	char    *argument;
	char    *element;
	t_list	*head;
	
	if (argc == 1)
	{
		printf("ERROR(0)\n");
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
			if (ft_checkElement(element) == 1)
			{	
				printf("------PUSH NUMBER--------\n");
				ft_pushNumber(element, stack);
				printf("-------------------------\n");
			}
			else
			{
				printf("ERROR(1)\n");
				return (0);
			}
			element = ft_nextElement(element);
			printf("Elemnto: %s\n", element);
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
		{
			printf("ERROR(1)");
			return (NULL);
		}
	}
	while (element[i] == ' ' || element[i] == '\t' || element[i] == '\n'
		|| element[i] == '\r' || element[i] == '\v' || element[i] == '\f' )
		i++;
	if (element[i] == '\0')
		return (NULL);
	return (&element[i]);
}

int ft_checkElement(char *element)
{
	int i;
	
	i = 0;
	if (element[0] == '-' || element[0] == '+')
		i++;
	while (element[i] && ft_isalnum(element[i]))
	{
		//printf("IN\n");
		if (ft_isdigit(element[i]))
			i++;
		else
			return (0);
	}
	//printf("OUT\n");
	return (1);
}