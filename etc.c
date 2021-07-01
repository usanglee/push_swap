#include "push_swap.h"

void	print_error(char *str)
{
	ft_printf("Error (from %s)", str);
	exit(1);
}

void	list_print(t_li *a, t_li *b)
{
	ft_printf("stack A   ");
	while (a != NULL)
	{
		ft_printf("%4d|", a->data);
		a = a->next;
	}
	ft_printf("\n");
	ft_printf("stack B   ");
	while (b != NULL)
	{
		ft_printf("%4d|", b->data);
		b = b->next;
	}
	ft_printf("\n");
}

void		two_arr_free(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}
