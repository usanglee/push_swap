#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int main()
{
    t_info io;

    io.a = ext_malloc(1, sizeof(t_deque));
    io.b = ext_malloc(1, sizeof(t_deque));

    
    push_back(io.a, node_new(1));
    push_back(io.a, node_new(2));
    push_back(io.a, node_new(3));
    push_back(io.a, node_new(4));
    reverse(io.a, ' ');
    reverse(io.a, ' ');
    ft_printf("%d\n", io.a->top->data);
    ft_printf("%d\n", io.a->top->next->data);
    ft_printf("%d\n", io.a->top->next->next->data);
    ft_printf("%d\n", io.a->bottom->data);

    // push_front(io.a, node_new(3));
    // ft_printf("%d\n", io.a->top->data);
    // ft_printf("%d\n", io.a->bottom->data);
    // ft_printf("size: %d\n", io.a->size);

    // write(1, "\n", 1);

    // push_back(io.a, node_new(4));
    // ft_printf("%d\n", io.a->top->data);
    // ft_printf("%d\n", io.a->top->next->data);
    // ft_printf("%d\n", io.a->bottom->prev->data);
    // ft_printf("%d\n", io.a->bottom->data);
    // ft_printf("size: %d\n", io.a->size);
  
}