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

void	ft_printList(int_list *head)
{
	int_list	*node;

	node = head;
	while (node != NULL)
	{
		printf("%i\n",node->content);
		node = node->next;
	}
}

void	ft_freeList(int_list **list)
{
	int_list	*node;
	int_list	*reference;

	node = *list;
	while (node != NULL)
	{
		reference = node;
		node = node->next;
		free(reference);
		reference = NULL;
	}
	*list = NULL;
}

int	ft_existsInList(int number, int_list *head)
{
    int_list *current_node;
    
	current_node = head;
	while (current_node != NULL)
	{
        if (current_node->content == number)
            return (1);
        current_node = current_node->next;
    }
    return (0);
}