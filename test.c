#include "push_swap.h"

int main(int ac, char **av)
{
	t_info	io;
	t_node	*temp;

	io.a = ext_malloc(1, sizeof(t_deque));
	io.b = ext_malloc(1, sizeof(t_deque));
	if (ac <= 1)
		return (0);
	if (ac == 2)
		ac_2(&io, av[1]);
	else
		ac_many(&io, ac - 1, av + 1);
	check_isdigit(io.split);
	make_deque(&io);
	io.arr = make_arr(io.a, io.a->size);
	quick_sort(io.arr, 0, io.len_arg - 1);
	check_duplicate(&io);
	if (check_sort(io.a) == 1)
		return (0);
	free(io.arr);
	push_back(io.b, node_new(98));
	push_back(io.b, node_new(99));
	push_back(io.b, node_new(100));
	command(&io, "pb");
	command(&io, "pa");
	ft_printf("A ");
	while (io.a->top)
	{
		ft_printf("%d ", io.a->top->data);
		io.a->top = io.a->top->next;
	}
	ft_printf("\n");
	ft_printf("B ");
	while (io.b->top)
	{
		ft_printf("%d ", io.b->top->data);
		io.b->top = io.b->top->next;
	}
	ft_printf("\n");
	return (0);
}
