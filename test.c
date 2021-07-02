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

int main()
{
	t_li *temp;
	temp = list_new(10);
	list_add(&temp, list_new(20));
	swap(&temp);
}
