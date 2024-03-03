#include "push_swap.h"

int main(int argc, char **argv)
{
    char    *str;
    t_list  **stackA;

    str = "-123 456";
    stackA = (t_list **)malloc(sizeof(t_list *));
    if (stackA == NULL)
        return (0);
    ft_pushNumber(str,stackA);
    printf("%i\n", *(int*)((*stackA)->content));
    return (0);
}