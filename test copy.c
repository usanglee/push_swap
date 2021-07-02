#include "./libft/libft.h"
#include <stdio.h>

int new_get_next_line(int fd, char **line)
{
	static t_list *li;
	int read_size;
	char *buf;
	char *chr_ret;
	int flag;

	read_size = read(fd, buf, 3);
	while (read_size > 0)
	{
		chr_ret = ft_strchr(buf, '\n');
		if (chr_ret == NULL)
		{
			flag = 1;
			ft_lstadd_back(&li, ft_lstnew(ft_strdup(buf)));
		}
		else
		{
			if (flag == 1)
			{
				flag = 0;
				ft_lstlast(li)->content = ft_strjoin(ft_lstlast(li)->content, buf);
			}
			*line = ft_substr(buf, 0, chr_ret - buf);
			chr_ret++;
			buf = chr_ret;
			chr_ret = ft_strchr(buf, '\n');
			if (chr_ret == NULL)
			{

			}
		}
		read_size = read(fd, buf, 3);
	}

}

int main()
{
	char *line;
	int fd;

	fd = open("test.txt", O_RDONLY);
	while (new_get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}

}