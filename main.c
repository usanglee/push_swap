#include "push_swap.h"

int		main(int ac, char **av)
{
	t_info io;
	io.a = ft_salloc(1, sizeof(t_deque));
    io.b = ft_salloc(1, sizeof(t_deque));

	if (ac <= 1)
		return (0);
	if (ac == 2)
		ac_2(&io, av[1]);
	else
		ac_many(&io, ac - 1, av + 1);
	check_isdigit(io.split);
	make_list(&io);
	make_arr(&io);
	sort_arr(io.arr, 0, io.len_arg - 1);
	check_duplicate(&io);
	rotate(io.a, ' ');
	while (io.a->top)
	{
		ft_printf("%d\n", io.a->top->data);
		io.a->top = io.a->top->next;
	}
}
