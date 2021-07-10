#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int main()
{
    t_info io;

    io.a = ft_salloc(1, sizeof(t_deque));
    io.b = ft_salloc(1, sizeof(t_deque));

    
    push_back(io.a, node_new(1));
    push_back(io.a, node_new(2));
    push_back(io.a, node_new(3));
    push_back(io.b, node_new(4));
    // ft_printf("%d\n", io.a->top->data);
    // ft_printf("%d\n", io.b->top->data);
    push(io.a, io.b, ' ');
    push(io.a, io.b, ' ');
    ft_printf("%d\n\n", io.a->top->data);
    ft_printf("%d\n\n", io.a->bottom->data);
    ft_printf("%d\n", io.b->top->data);
    ft_printf("%d\n", io.b->top->next->data);
    ft_printf("%d\n", io.b->bottom->data);

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