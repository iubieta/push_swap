#include "push_swap.h"

void	main(int argc, char **argv)
{
	t_list	**stack_A;
	t_list	**stack_B;
	t_list	*head_A;
	t_list	*head_B;
	
	int		i;
	int		a;
	int		b;
	int		move;
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
		
		a = fastest;
		b = ft_find_place(*stack_B, a, 'd');
		printf("Place: %i\n", b);
		
		move = ft_get_move(*stack_A, *stack_B, a, b);
		printf("------------------\n");
		printf("Move: %i\n",move);
		
		ft_print_move(move, *stack_A, *stack_B, a, b);

		ft_apply_move(move, stack_A, stack_B, a, b);
		printf("------------------\n");
		printf("Stack A:\n");
		ft_print_list(head_A);
		printf("Stack B:\n");
		ft_print_list(head_B);
		
		ft_push_between(stack_A, stack_B);
		printf("------------------\n");
		printf("Push\n");
		printf("pb\n");
		printf("------------------\n");
		printf("Stack A:\n");
		ft_print_list(head_A);
		printf("Stack B:\n");
		ft_print_list(head_B);
		i++;
	}
}