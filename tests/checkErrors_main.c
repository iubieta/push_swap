#include "push_swap.h"

int main(int argc, char **argv)
{
	char        *str;
	t_list    **stackA;
	t_list    *headA;

	headA = NULL;
	stackA = &headA;
	if (ft_check_errors(argc, argv, stackA) == 0)
		{
			ft_free_list(stackA);
			stackA = NULL;
			printf("%p\n",headA);
			printf("%p\n",stackA);
		}
	if (stackA)
	{
		printf("StackA:\n");
		ft_print_list(headA);
	}
	else
		printf("STACK_A LIBERADO\n");
	return (0);
}