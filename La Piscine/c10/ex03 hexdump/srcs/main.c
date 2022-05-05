/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:19:31 by jayang            #+#    #+#             */
/*   Updated: 2022/02/21 19:44:40 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
void print_hex_addr(void);
void print_hex_addr2(void);

void	ft_print_errno(char *param_str, int err)
{
	ft_putstr(basename(g_path));
	ft_putstr(": ");
	ft_putstr(param_str);
	ft_putstr(": ");
	ft_putstr(strerror(err));
	ft_putchar('\n');
}

void	bad_type_err(char *str)
{
	ft_putstr(basename(g_path));
	ft_putstr(": ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putstr("Bad file descriptor");
	ft_putchar('\n');
}

void	vacate_buffer(int option)
{
	if (option == 0)
	{
		ft_print_hex(g_file, g_idx);
		g_addr += (unsigned long long)g_idx;
		print_hex_addr();
		ft_putchar('\n');
	}
	else
	{
		ft_print_hex_option(g_file, g_idx);
		g_addr += (unsigned long long)g_idx;
		print_hex_addr2();
		ft_putchar('\n');
	}
}

void	ft_read_file(int is_end, int fd, int option)
{
	int	byte;

	g_flag = 0;
	while (1)
	{
		byte = read(fd, g_file + g_idx, 1);
		if (byte <= 0)
			break ;
		if (option == 0 && g_idx == 15)
			ft_print_hex(g_file, 16);
		else if (option == 1 && g_idx == 15)
			ft_print_hex_option(g_file, 16);
		g_idx = (g_idx + 1) % 16;
		if (g_idx == 0)
			g_addr += 16;
	}
	if (is_end)
		vacate_buffer(option);
}

void	ft_open_file(int is_end, char *argv, int option)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_print_errno(argv, errno);
		if (is_end && g_err == 0)
			bad_type_err(argv);
		return ;
	}
	g_err = 1;
	ft_read_file(is_end, fd, option);
	close(fd);
}

void	handle_option(int argc, char *argv[], int param)
{
	if (argc == 2)
		ft_read_file(1, 0, 1);
	while (param < argc)
	{
		ft_open_file(param == argc - 1, argv[param], 1);
		param++;
	}
}

int	main(int argc, char *argv[])
{
	int	param;

	g_path = argv[0];
	g_flag = 0;
	g_err = 0;
	g_idx = 0;
	param = 1;
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'C')
		handle_option(argc, argv, param + 1);
	else
	{
		if (argc == 1)
			ft_read_file(1, 0, 0);
		while (param < argc)
		{
			ft_open_file(param == argc - 1, argv[param], 0);
			param++;
		}
	}
	return (0);
}