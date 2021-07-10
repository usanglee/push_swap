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
		push_back(io->a, node_new((int)num));
		i++;
	}
	two_arr_free(io->split);
}

void	make_arr(t_info *io)
{
	int i;
	int sort_flag;
	int before;
	t_node *temp;

	temp = io->a->top;
	io->arr = (int *)malloc(sizeof(int) * io->len_arg);
	sort_flag = 1;
	before = -2147483648;
	i = 0;
	while (i < io->len_arg)
	{
		if (before == temp->data)
			print_error("check_duplicate");
		if (before > temp->data)
			sort_flag = 0;
		before = temp->data;
		io->arr[i++] = temp->data;
		temp = temp->next;
	}
	if (sort_flag)
		exit(1);
}
