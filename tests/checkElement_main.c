#include "push_swap.h"

int main(int argc, char **argv)
{
    char    *str;
	char	*element;

    str = "   -123 +456 aaa";
    element = ft_nextElement(str);
    while (element)
	{
		printf("Elemento: %s\n",element);
		printf("Return: %i\n", ft_checkElement(element));
		element = ft_nextElement(element);
	}
    return (0);
}