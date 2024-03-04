#include "push_swap.h"

int_list *ft_lst_newNode(int content)
{
	int_list *newNode;

	newNode = malloc(sizeof(int_list));
	if (newNode == NULL)
		return (NULL);
	newNode->content = content;
	newNode->next = NULL;
	return (newNode);
}

void	ft_lst_addFront(int_list **list, int_list *node)
{
	if (node != NULL)
	{
		node->next = *list;
		*list = node;
	}
}

void	ft_printList(int_list **list)
{
	int_list	*node;

	node = *list;
	while (node != NULL)
	{
		printf("%i\n",node->content);
		node = node->next;
	}
}

int	ft_existsInList(int number, int_list *head)
{
    int_list *current_node = head;
    while (current_node != NULL)
	{
        if (current_node->content == number)
            return 1;
        current_node = current_node->next;
    }
    return 0;
}



void	ft_pushNumber(char *element, int_list **stack)
{
	int			number;
	int_list	*node;

	if (!stack)
	{
		stack = malloc(sizeof(int_list *));
		if (stack == NULL)
			return;
	}
	number = ft_atoi(element);
	node = ft_lst_newNode(number);
	ft_lst_addFront(stack, node);
}