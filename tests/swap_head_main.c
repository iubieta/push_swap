#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_A;
	t_list	*head_A;

	head_A = NULL;
	stack_A = &head_A;
	
	printf("---------INICIO-----------\n");
	if (ft_check_errors(argc, argv, stack_A) == 0)
		return (0);

	printf("Stack A:\n");
	ft_print_list(head_A);

	ft_swap_head(stack_A);
	printf("Stack A:\n");
	ft_print_list(head_A);
}