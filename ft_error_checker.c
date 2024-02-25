#include "push_swap.h"

int ft_checkErrors(int argc, char **argv)
{
	int     i;
	char    *argument;
	char    *element;
	
	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		argument = argv[i];
		printf("Argumento %i: %s\n",i,argument);
		element = ft_nextElement(argument);
		while (element[0] != '\0')
		{
			printf("Elemento: %s\n", element);
			if (ft_checkElement(element) == 1)
				printf("Numero correcto: %s\n",element);
				//ft_pushElement(ft_atoi(element));
			else
			{
				printf("ERROR\n");
				return (0);
			}
			element = ft_nextElement(element);
			fflush(stdout);
			sleep(1);
		}
		i++;
	}
}

char	*ft_nextElement(char *element)
{
	int	i;
	
	i = 0;
	if (element[i] == '\0')
		return (NULL); 
	if (ft_isalnum(element[0]) == 1)
		while (ft_isalnum(element[i]) == 1)
			i++;
	while (element[i] == ' ' || element[i] == '\t' || element[i] == '\n'
		|| element[i] == '\r' || element[i] == '\v' || element[i] == '\f' )
		i++;
	return (&element[i]);
}

int ft_checkElement(char *element)
{
	int i;
	
	i = 0;
	while (element[i] && element[i] != ' ')
	{
		if (element[0] == '-' || element[0] == '+')
			i++;
		if (element[i] >= '0' && element[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}