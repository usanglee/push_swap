#include "push_swap.h"

void	swap(t_li **li)
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

void	push(t_li **src, t_li **dest, int flag)
{
	if (*src == NULL)
		return ;
	if (*dest == NULL)
	{
		*dest = *src;
		*src = (*src)->next;
		(*src)->prev = NULL;
		(*dest)->next = NULL;
	}
	else
	{
		(*dest)->prev = *src;
		*src = (*src)->next;
		if (*src != NULL)
			(*src)->prev = NULL;
		(*dest)->prev->next = *dest;
		*dest = (*dest)->prev;
	}
	if (flag == 'a')
		ft_printf("pa\n");
	else if (flag == 'b')
		ft_printf("pb\n");
}

void	rotate(t_li **li, int flag)
{
	if (*li == NULL | (*li)->next == NULL)
		return ;
	*li = (*li)->next;
	(*li)->prev->prev = list_last(*li);
	list_last(*li)->next = (*li)->prev;
	(*li)->prev->next = NULL;
	(*li)->prev = NULL;
	if (flag == 'a')
		ft_printf("ra\n");
	else if (flag == 'b')
		ft_printf("rb\n");
}

void	reverse(t_li **li, int flag)
{
	if (*li == NULL | (*li)->next == NULL)
		return ;
	(*li)->prev = list_last(*li);
	(*li)->prev->next = (*li);
	(*li)->prev->prev->next = NULL;
	(*li) = (*li)->prev;
	(*li)->prev = NULL;
	if (flag == 'a')
		ft_printf("rra\n");
	else if (flag == 'b')
		ft_printf("rrb\n");
}

void	command(t_info *io, char *str)
{
//	if (!ft_strcmp(str, "sa"))
	//	swap(&(io->a), 'a');
	// else if (!ft_strcmp(str, "sb"))
	// 	swap(&(io->b), 'b');
	// else if (!ft_strcmp(str, "ss"))
	//		swap_both(&(io->a), &(io->b));
	if (!ft_strcmp(str, "pa"))
		push(&(io->b), &(io->a), 'a');
	else if (!ft_strcmp(str, "pb"))
		push(&(io->a), &(io->b), 'b');
	else if (!ft_strcmp(str, "rra"))
		reverse(&(io->a), 'a');
	else if (!ft_strcmp(str, "rrb"))
		reverse(&(io->b), 'b');
	else if (!ft_strcmp(str, "rrr"))
		reverse_both(&(io->a), &(io->b));
	else if (!ft_strcmp(str, "ra"))
		rotate(&(io->a), 'a');
	else if (!ft_strcmp(str, "rb"))
		rotate(&(io->b), 'b');
	else if (!ft_strcmp(str, "rr"))
		rotate_both(&(io->a), &(io->b));
	else
		print_error("command");

}

