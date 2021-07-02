#include "push_swap.h"

t_li	*list_new(int num)
{
	t_li *li;

	li = malloc(sizeof(t_li));
	li->data = num;
	li->prev = NULL;
	li->next = NULL;
	return (li);
}

void	list_add(t_li **li, t_li *new)
{
	t_li *last_node;

	if (*li == NULL)
	{
		*li = new;
		return ;
	}
	if ((*li)->prev != NULL)
		last_node = (*li)->prev;
	else
		last_node = *li;
	new->prev = last_node;
	last_node->next = new;
	new->next = *li;
	(*li)->prev = new;
}
