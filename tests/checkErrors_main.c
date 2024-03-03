#include "push_swap.h"

void	ft_printList(int_list **list);
void ft_freeList(int_list **list);

int main(int argc, char **argv)
{
    char        *str;
    int_list    *stackA;

    stackA = NULL;
    printf("-------CHECK ERRORS--------\n");
    ft_checkErrors(argc, argv, &stackA);
    printf("---------------------------\n");
    fflush(stdout);
	sleep(1);
    ft_printList(&stackA);
    ft_freeList(&stackA);
    return (0);
}