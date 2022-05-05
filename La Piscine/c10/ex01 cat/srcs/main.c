/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:23:39 by jayang            #+#    #+#             */
/*   Updated: 2022/02/19 17:30:27 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>
#include <fcntl.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_write(char *str, int size);
char	*path;

void	ft_print_errno(char *param_str, int err)
{
	ft_putstr(basename(path));
	ft_putstr(": ");
	ft_putstr(param_str);
	ft_putstr(": ");
	ft_putstr(strerror(err));
	ft_putchar('\n');
}

void	ft_read(int fd)
{
	int		byte;
	char	file[30];

	while (1)
	{
		byte = read(fd, file, 10);
		if (byte != 0)
			ft_write(file, byte);
		else
			break;
	}
}

void	ft_open_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_print_errno(argv, errno);
		return ;
	}
	ft_read(fd);
	close(fd);
}

int	main(int argc, char *argv[])
{
	int		param;

	param = 1;
	path = argv[0];
	if (argc == 1)
		ft_read(0);
	else
	{
		while (param < argc)
		{
			ft_open_file(argv[param]);
			param++;
		}
	}
	return (0);
}