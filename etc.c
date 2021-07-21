#include "push_swap.h"

void	print_error(char *str)
{
	ft_printf("Error (from %s)", str);
	exit(1);
}

void	*ext_malloc(size_t n, size_t size)
{
	void	*ret;

	ret = (char *)malloc(size * n);
	if (!ret)
		print_error("malloc error");
	ft_bzero(ret, (n * size));
	return (ret);
}

void	list_print(t_node *a, t_node *b)
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
