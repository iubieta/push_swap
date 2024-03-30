#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_A;
	t_list	**stack_B;
	t_list	*head_A;
	t_list	*head_B;

	head_A = NULL;
	head_B = NULL;
	stack_A = &head_A;
	stack_B = &head_B;
	
	if (ft_check_errors(argc, argv, stack_B) == 0)
		return(0);
	while (head_B != NULL)
		ft_push_between(stack_B, stack_A);
	ft_mechanical_turk(stack_A, stack_B);
	return(1);
}
