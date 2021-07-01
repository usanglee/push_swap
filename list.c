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

t_li	*list_last(t_li *li)
{
	if (li == NULL)
		return (NULL);
	while (li->next != NULL)
		li = li->next;
	return (li);
}

void	list_add(t_li **li, t_li *new)
{
	if (*li == NULL)
	{
		*li = new;
		return ;
	}
	new->prev = list_last(*li);
	list_last(*li)->next = new;
}

int	list_len(t_li *li)
{
	int len = 0;

	while (li)
	{
		len++;
		li = li->next;
	}
	return (len);
}
