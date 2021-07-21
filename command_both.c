#include "push_swap.h"

void	swap_both(t_info *io)
{
	swap(io->a, ' ');
	swap(io->b, ' ');
	ft_printf("ss\n");
}

void	rotate_both(t_info *io)
{
	rotate(io->a, ' ');
	rotate(io->b, ' ');
	ft_printf("rr\n");
}

void	reverse_both(t_info *io)
{
	reverse(io->a, ' ');
	reverse(io->b, ' ');
	ft_printf("rrr\n");
}
