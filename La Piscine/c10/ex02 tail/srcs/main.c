/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:29:37 by jayang            #+#    #+#             */
/*   Updated: 2022/02/21 21:32:39 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	ft_write(int idx, int buf, int flag)
{
	int	i;

	i = idx;
	if (i != 0)
	{
		while (i < buf && flag == 1)
		{
			write(1, g_cont + i, 1);
			i++;
		}
		i = 0;
	}
	while (i < idx)
	{
		write(1, g_cont + i, 1);
		i++;
	}
}

void	ft_read_file(int fd, int buf)
{
	int		byte;
	int		idx;
	int		flag;
	char	file[1];

	idx = 0;
	flag = 0;
	while (1)
	{
		byte = read(fd, file, 1);
		if (byte == 0)
			break ;
		if (buf != 0)
		{
			if (idx == buf)
			{
				flag = 1;
				idx = 0;
			}
			g_cont[idx] = file[0];
			idx++;
		}
	}
	if (buf != 0)
		ft_write(idx, buf, flag);
}

void	ft_open_file(int param, int argc, char *argv, int buf)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_print_errno(argv, errno);
		return ;
	}
	if (argc > 4)
	{
		if (param != 3 && g_errflag == 0)
			ft_putchar('\n');
		ft_putstr("==> ");
		ft_putstr(argv);
		ft_putstr(" <==\n");
	}
	g_errflag = 0;
	ft_read_file(fd, buf);
	close(fd);
}

void	ctrl_param_3up(int argc, char *argv[])
{
	int		buf;
	int		param;

	param = 3;
	while (param < argc)
	{
		buf = ft_atoi(argv[2]);
		g_cont = (char *)malloc(sizeof(char) * (buf));
		if (!g_cont)
			return ;
		ft_open_file(param, argc, argv[param], buf);
		free(g_cont);
		param++;
	}
}

int	main(int argc, char *argv[])
{
	int		buf;

	if (argc < 3)
		return (0);
	g_path = argv[0];
	g_errflag = 1;
	if (argc == 3)
	{
		buf = ft_atoi(argv[2]);
		g_cont = (char *)malloc(sizeof(char) * buf);
		if (!g_cont)
			return (0);
		ft_read_file(0, buf);
		free(g_cont);
	}
	else
		ctrl_param_3up(argc, argv);
	return (0);
}