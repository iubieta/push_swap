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
	printf("Stack A:\n");
	ft_print_list(head_A);
	printf("-----MECHANICAL TURK------\n");
	mechanical_turk(stack_A, stack_B);
	printf("----------END-------------\n");
	printf("Stack A:\n");
	ft_print_list(head_A);
	return;
}

void	mechanical_turk(t_list **stack_A, t_list **stack_B)
{
	int	i;
	int len;
	int	fastest_number;

	ft_push_between(stack_A, stack_B);
	ft_push_between(stack_A, stack_B);
	printf("Stack A:\n");
	ft_print_list(*stack_A);
	printf("Stack B:\n");
	ft_print_list(*stack_B);
	printf("------------\n");
	
	//SORT B
	i = 0;
	len = ft_list_len(*stack_A);
	while (i < len - 3)
	{
		fastest_number = ft_fastest_number(*stack_A, *stack_B);
		ft_sort_number(stack_A, stack_B, fastest_number, 'd');
		ft_push_between(stack_A, stack_B);
		ft_printf("pb\n");
		i++;
	}
	printf("Sort B:\n");
	printf("------------\n");
	printf("Stack A:\n");
	ft_print_list(*stack_A);
	printf("Stack B:\n");
	ft_print_list(*stack_B);
	printf("------------\n");
	
	//SORT THREE
	ft_sort_three(stack_A);
	printf("Sort three:\n");
	printf("------------\n");
	printf("Stack A:\n");
	ft_print_list(*stack_A);
	printf("Stack B:\n");
	ft_print_list(*stack_B);
	printf("------------\n");
	
	//HIGHEST AT TOP
	ft_rotate_down(stack_A);
	printf("Highest at top:\n");
	printf("------------\n");
	printf("Stack A:\n");
	ft_print_list(*stack_A);
	printf("Stack B:\n");
	ft_print_list(*stack_B);
	printf("------------\n");
	
	//PUSH B
	i = 0;
	len = ft_list_len(*stack_B);
	while (i++ < len)
	{
		ft_sort_number(stack_B, stack_A, (*stack_B)->content, 'a');
		ft_push_between(stack_B, stack_A);
		ft_printf("pa\n");
	}
	printf("Sort A:\n");
	printf("------------\n");
	printf("Stack A:\n");
	ft_print_list(*stack_A);
	printf("Stack B:\n");
	ft_print_list(*stack_B);
	printf("------------\n");
}