#include "push_swap.h"

int		main(int ac, char **av)
{
	t_info io;

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

	t_li *temp;
	while (io.a)
	{
		temp = io.a;
		while (temp)
		{
			temp->cost_move = 0;
			temp->cost_sort = 0;
			temp->reverse_move = 0;
			temp->reverse_sort = 0;
			temp = temp->next;
		}
		set_cost_move(&io);
		set_cost_sort(&io);
		raise_node(&io);
		sort_node(&io);
	}
}
