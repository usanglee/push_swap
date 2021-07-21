#include "push_swap.h"

void	make_deque(t_info *io)
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

int		*make_arr(t_deque *deq, int size)
{
	t_node *temp;
	int i;
	int *arr;

	temp = deq->top;
	arr = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
	return (arr);
}
