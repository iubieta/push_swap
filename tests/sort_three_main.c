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
	if (ft_list_len(*stack_A) != 3)
	{
		printf("ERROR: la lista no es de 3 numeros");
		return;
	}
	printf("Stack A:\n");
	ft_print_list(head_A);

	ft_sort_three(stack_A);
	printf("Stack A:\n");
	ft_print_list(head_A);
	if (ft_sorted(head_A) == 1)
		printf("Lista Ordenada\n");
	else
		printf("ERROR\n");
}