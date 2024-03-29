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

	printf("Lista Ordenada?\n");
	if (ft_sorted(head_A) == 1)
		printf("SI\n");
	else
		printf("NO\n");
}