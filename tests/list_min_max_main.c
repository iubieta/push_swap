#include "push_swap.h"

void main(int argc, char **argv)
{
	t_list	**stack_A;
	t_list	*head_A;
	int		min;
	int		max;

	head_A = NULL;
	stack_A = &head_A;
	
	printf("---------INICIO-----------\n");
	if (ft_check_errors(argc, argv, stack_A) == 0)
		return;

	printf("Stack A:\n");
	ft_print_list(head_A);

	min = ft_list_min(*stack_A);
	max = ft_list_max(*stack_A);
	printf("Min = %i\n",min);
	printf("Max = %i\n",max);
}