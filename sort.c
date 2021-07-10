#include "push_swap.h"

void	set_cost_move(t_info *io)
{
	t_node *node;
	int i;

	i = 0;
	node = io->a;
	while (node)
	{
		node->cost_move = i;
		node = node->next;
		i++;
	}
	node = list_last(io->a);
	i = 1;
	while (node)
	{
		if (i < node->cost_move)
		{
			node->cost_move = i;
			node->reverse_move = 1;
		}
		node = node->prev;
		i++;
	}
}

void	set_cost_sort(t_info *io)
{
	t_node *top_node;
	t_node *stack_b;
	int i;

	i = 0;
	top_node = io->a;
	while (top_node)
	{
		i = 0;
		stack_b = io->b;
		while (stack_b)
		{
			if (top_node->data > stack_b->data)
				break;
			i++;
			stack_b = stack_b->next;
		}
		top_node->cost_sort = i;
		if (i == 1)
			top_node->cost_sort = 2;

		stack_b = list_last(io->b);
		i = 0;
		while (stack_b)
		{
			if (top_node->data < stack_b->data)
				break;
			i++;
			stack_b = stack_b->prev;
		}
		if (top_node->cost_sort > i)
		{
			top_node->reverse_sort = 1;
			top_node->cost_sort = i;
		}
		top_node = top_node->next;
	}
}

int		get_min_node(t_info *io)
{
	unsigned int min;
	int i;
	int node_value;
	t_node *stack_a;

	stack_a = io->a;
	min = 2147483648;
	while (stack_a)
	{
		if (min > (stack_a->cost_move + stack_a->cost_sort))
		{
			min = (stack_a->cost_move + stack_a->cost_sort);
			node_value = stack_a->data;
		}
		stack_a = stack_a->next;
	}
	return (node_value);
}

void	raise_node(t_info *io)
{
	t_node *stack_a;
	int min_node_value;
	int i;
	int count;

	count = 0;
	min_node_value = get_min_node(io);
	ft_printf("min node: %d\n", min_node_value);
	stack_a = io->a;
	while (min_node_value != stack_a->data)
		stack_a = stack_a->next;
	if (stack_a->reverse_move)
	{
		if (stack_a->reverse_sort == 1)
		{
			if (stack_a->cost_move > stack_a->cost_sort)
			{
				count = stack_a->cost_sort;
				stack_a->rr_count = count;
				stack_a->cost_move -= count;
				while (count--)
					command(io, "rrr");
				while (stack_a->cost_move--)
					command(io, "rra");
			}
			else
			{
				count = stack_a->cost_move;
				stack_a->rr_count = count;
				stack_a->cost_move -= count;
				while (count--)
					command(io, "rrr");
			}
		}
		else
		{
			while (stack_a->cost_move--)
				command(io, "rra");
		}
	}
	else
	{
		if (stack_a->reverse_sort == 1)
		{
			while (stack_a->cost_move--)
				command(io, "ra");
		}
		else
		{
			if (stack_a->cost_move > stack_a->cost_sort)
			{
				count = stack_a->cost_sort;
				stack_a->rr_count = count;
				stack_a->cost_move -= count;
				while (count--)
					command(io, "rr");
				while (stack_a->cost_move--)
					command(io, "ra");
			}
			else
			{
				count = stack_a->cost_move;
				stack_a->rr_count = count;
				stack_a->cost_move -= count;
				while (count--)
					command(io, "rr");
			}
		}

	}
}

void	sort_node(t_info *io)
{
	int count;
	int reverse;
	int ra_count;

	ra_count = 0;
	reverse = io->a->reverse_sort;

	if (reverse == 1)
	{
		count = io->a->cost_sort - io->a->rr_count;
		while (count--)
		{
			command(io, "rrb");
			ra_count++;
		}
		command(io, "pb");
		ra_count++;
		ra_count += io->a->rr_count;
		while (ra_count--)
			command(io, "rb");
	}
	else
	{
		count = io->a->cost_sort - io->a->rr_count;
		if (io->a->cost_sort == 2)
		{
			command(io, "pb");
			command(io, "sb");
		}
		else
		{
			while (count--)
			{
				command(io, "rb");
				ra_count++;
			}
			ra_count += io->a->rr_count;
			command(io, "pb");
			while (ra_count--)
				command(io, "rrb");
		}
	}
}