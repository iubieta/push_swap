#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_A;
	t_list	**stack_B;
	t_list	*head_A;
	t_list	*head_B;
	int		i;

	head_A = NULL;
	head_B = NULL;
	stack_A = &head_A;
	stack_B = &head_B;
	printf("---------INICIO-----------\n");
	if (ft_check_errors(argc, argv, stack_A) == 0)
		return (0);
	printf("Stack A:\n");
	ft_print_list(head_A);
	printf("Stack B:\n");
	ft_print_list(head_B);
	i = 1;
	while (i < 10)
	{
		ft_push_between_lists(stack_A, stack_B);
		printf("Stack A (%i):\n", i);
		ft_print_list(head_A);
		printf("Stack B(%i):\n", i);
		ft_print_list(head_B);
		i++;
	}
}