#include "push_swap.h"

void main(int argc, char **argv)
{
	t_list	**stack_A;
	t_list	*head_A;
	int		len;

	head_A = NULL;
	stack_A = &head_A;
	
	printf("---------INICIO-----------\n");
	if (ft_check_errors(argc, argv, stack_A) == 0)
		return;

	printf("Stack A:\n");
	ft_print_list(head_A);

	len = ft_list_len(*stack_A);
	printf("Len = %i\n",len);
}