#include "push_swap.h"

void	swap_both(t_li **a, t_li **b)
{
	swap(a, ' ');
	swap(b, ' ');
	ft_printf("ss\n");
}

void	rotate_both(t_li **a, t_li **b)
{
	rotate(a, ' ');
	rotate(b, ' ');
	ft_printf("rr\n");
}

void	reverse_both(t_li **a, t_li **b)
{
	reverse(a, ' ');
	reverse(b, ' ');
	ft_printf("rrr\n");
}
