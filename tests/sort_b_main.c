#include "push_swap.h"

void	main(int argc, char **argv)
{
	t_list	**stack_A;
	t_list	**stack_B;
	t_list	*head_A;
	t_list	*head_B;
	
	int		i;
	int		len;
	int		fastest;

	head_A = NULL;
	head_B = NULL;
	stack_A = &head_A;
	stack_B = &head_B;
	
	printf("---------INICIO-----------\n");
	if (ft_check_errors(argc, argv, stack_A) == 0)
		return;
	
	ft_push_between(stack_A, stack_B);
	ft_push_between(stack_A, stack_B);
	
	printf("Stack A:\n");
	ft_print_list(head_A);
	printf("Stack B:\n");
	ft_print_list(head_B);
	len = ft_list_len(*stack_A);
	
	i = 0;
	while (i < len)
	{
		fastest = ft_fastest_number(*stack_A, *stack_B);
		printf("------------------\n");
		printf("Fastest number: %i\n",fastest);
		
		ft_sort_number(stack_A, stack_B, fastest, 'd');
		printf("------------------\n");
		printf("Stack A:\n");
		ft_print_list(head_A);
		printf("Stack B:\n");
		ft_print_list(head_B);
		printf("------------------\n");
		
		ft_push_between(stack_A, stack_B);
		printf("PUSH\n");
		printf("------------------\n");
		printf("Stack A:\n");
		ft_print_list(head_A);
		printf("Stack B:\n");
		ft_print_list(head_B);
		i++;
	}
	return;
}