#include "push_swap.h"

void	ft_printList(int_list **list);
void ft_freeList(int_list **list);

int main(int argc, char **argv)
{
    char        *str;
    int_list    **stackA;

    stackA = NULL;
    ft_checkErrors(argc, argv, stackA);

    fflush(stdout);
	sleep(1);
    if (stackA)
        ft_printList(stackA);
    return (0);
}