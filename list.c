#include "push_swap.h"

t_node	*node_new(int num)
{
	t_node *node;

	node = ft_salloc(1, sizeof(t_node));
	node->data = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push_front(t_deque *deque, t_node *node)
{
	if (deque == NULL || node == NULL)
		return ;
	if (deque->top == NULL || deque->bottom == NULL)
	{
		deque->top = node;
		deque->bottom = node;
		deque->size++;
		return ;
	}
	node->next = deque->top;
	deque->top->prev = node;
	node->prev = NULL;
	deque->top = node;
	deque->size++;
}

void	push_back(t_deque *deque, t_node *node)
{
	if (deque == NULL || node == NULL)
		return ;
	if (deque->top == NULL || deque->bottom == NULL)
	{
		deque->top = node;
		deque->bottom = node;
		deque->size++;
		return ;
	}
	deque->bottom->next = node;
	node->prev = deque->bottom;
	node->next = NULL;
	deque->bottom = node;
	deque->size++;
}

void	remove_front(t_deque *deque)
{
	if (deque == NULL)
		return ;
	if (deque->top == deque->bottom)
	{
		deque->top = NULL;
		deque->bottom = NULL;
		deque->size--;
		return ;
	}
	deque->top = deque->top->next;
	deque->top->prev = NULL;
	deque->size--;
}

void	remove_back(t_deque *deque)
{
	if (deque == NULL)
		return ;
	if (deque->top == deque->bottom)
	{
		deque->top = NULL;
		deque->bottom = NULL;
		return ;
	}
	deque->bottom = deque->bottom->prev;
	deque->bottom->next = NULL;
	deque->size--;
}
