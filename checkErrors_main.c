#include "push_swap.h"

int main(int argc, char **argv)
{
	char        *str;
	int_list    **stackA;
	int_list    *headA;

	headA = NULL;
	stackA = &headA;
	if (ft_checkErrors(argc, argv, stackA) == 0)
		{
			ft_freeList(stackA);
			stackA = NULL;
			printf("%p\n",headA);
			printf("%p\n",stackA);
		}
	if (stackA)
	{
		printf("StackA:\n");
		ft_printList(headA);
	}
	else
		printf("STACK_A LIBERADO\n");
	return (0);
}