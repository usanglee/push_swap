#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void    swap(t_li **li)
{
    t_li *first_node;

    if (*li == NULL || (*li)->next == NULL)
        return ;
    first_node = *li;
    *li = (*li)->next;
    if ((*li)->next != first_node)
    {
        first_node->next = (*li)->next;
        (*li)->next = first_node;
        (*li)->prev = first_node->prev;
        first_node->prev = *li;
    }
}

void	push(t_li **src, t_li **dest)
{
	t_li *move_node;

	if (*src == NULL)
		return ;
	if (*dest == NULL)
	{
		*src = (*src)->next;

	}

	move_node = *src;
	*src = (*src)->next;
	(*src)->prev = move_node->prev;
	move_node->prev = (*dset)->prev;
	move_node->next = *dest;
	*dest = move_node;
}
int main()
{
	t_li *temp;
	temp = list_new(10);
	swap(&temp);
}
