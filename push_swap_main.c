#include "push_swap.h"

void	main(int argc, char **argv)
{
	t_list	**stack_A;
	t_list	**stack_B;
	t_list	*head_A;
	t_list	*head_B;

	head_A = NULL;
	head_B = NULL;
	stack_A = &head_A;
	stack_B = &head_B;
	
	printf("---------INICIO-----------\n");
	if (ft_check_errors(argc, argv, stack_B) == 0)
		return;
	printf("Stack B:\n");
	ft_print_list(head_B);
	while (head_B != NULL)
		ft_push_between(stack_B, stack_A);
	printf("Stack A:\n");
	ft_print_list(head_A);
	printf("-----MECHANICAL TURK------\n");
	ft_mechanical_turk(stack_A, stack_B);
	printf("----------END-------------\n");
	printf("Stack A:\n");
	ft_print_list(head_A);
	return;
}
