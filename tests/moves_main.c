#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_A;
	t_list	**stack_B;
	t_list	*head_A;
	t_list	*head_B;
	
	t_list	*node;
	int		number;
	int		moves;
	int		min_moves;
	int		fastest;

	head_A = NULL;
	head_B = NULL;
	stack_A = &head_A;
	stack_B = &head_B;
	printf("---------INICIO-----------\n");
	if (ft_check_errors(argc, argv, stack_A) == 0)
		return (0);
	ft_push_between(stack_A, stack_B);
	ft_push_between(stack_A, stack_B);
	printf("Stack A:\n");
	ft_print_list(head_A);
	printf("Stack B:\n");
	ft_print_list(head_B);
	node = head_A;
	fastest = node->content;
	min_moves = INT_MAX;
	while (node != NULL)
	{
		ft_printf("-------------------");
		number = node->content;
		ft_printf("Number: %i\n",number);
		moves = ft_moves(head_A, head_B, number);
		ft_printf("Moves: %i\n", moves);
		if (moves < min_moves)
		{
			min_moves = moves;
			fastest = number;
		}
		ft_printf("Fastest Number: %i\n",fastest);
		ft_printf("Moves: %i\n", min_moves);
		node = node->next;
	}
	return (fastest);
}