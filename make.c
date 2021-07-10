#include "push_swap.h"

void	make_list(t_info *io)
{
	int i;
	long long num;

	i = 0;
	while (i < io->len_arg)
	{
		num = ft_atol(io->split[i]);
		if (num < -2147483648 || num > 2147483647)
			print_error("make_list");
		list_add(&(io->a), node_new((int)num));
		i++;
	}
	two_arr_free(io->split);
}

void	make_arr(t_info *io)
{
	t_node *temp_li;
	int i;
	int sort_flag;
	int before;

	io->arr = (int *)malloc(sizeof(int) * io->len_arg);
	temp_li = io->a;
	sort_flag = 1;
	before = -2147483648;
	i = 0;
	while (i < io->len_arg)
	{
		if (before == temp_li->data)
			print_error("check_duplicate");
		if (before > temp_li->data)
			sort_flag = 0;
		before = temp_li->data;
		io->arr[i++] = temp_li->data;
		temp_li = temp_li->next;
	}
	if (sort_flag)
		exit(1);
}
