/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:24:49 by jayang            #+#    #+#             */
/*   Updated: 2022/02/22 10:44:34 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_wrong_char(char c, int *is_firstline, int *cnt)
{
	if (c == '\n')
	{
		if (*is_firstline)
		{
			g_mapinfo.x = *cnt;
			*is_firstline = 0;
		}
		else if (*cnt != g_mapinfo.x)
			return (1);
		*cnt = 0;
	}
	else
	{
		if (c == g_mapinfo.empty || c == g_mapinfo.obstacle)
			(*cnt)++;
		else
			return (1);
	}
	return (0);
}

int	is_wrong_map(int fd)
{
	int		byte;
	int		is_firstline;
	int		cnt;
	int		cycle;
	char	file[1];

	is_firstline = 1;
	cnt = 0;
	cycle = 0;
	while (1)
	{
		byte = read(fd, file, 1);
		if (byte == 0)
			break ;
		if (is_wrong_char(file[0], &is_firstline, &cnt))
			return (1);
		if (file[0] == '\n')
			cycle++;
	}
	if (g_mapinfo.y != cycle || g_mapinfo.x == 0)
		return (1);
	if (file[0] == '\n')
		return (0);
	return (1);
}

int	is_wrong_mapinfo(char *file, int size)
{
	int	idx;

	if (size < 4)
		return (1);
	idx = 1;
	while (idx <= 3)
	{
		if (!(' ' <= file[size - idx] && file[size - idx] <= '~'))
			return (1);
		idx++;
	}
	if (file[size - 1] == file[size - 2] || file[size - 2] == file[size - 3] || \
		file[size - 3] == file[size - 1])
		return (1);
	g_mapinfo.full = file[size - 1];
	g_mapinfo.obstacle = file[size - 2];
	g_mapinfo.empty = file[size - 3];
	file[size - 3] = '\0';
	g_mapinfo.y = ft_atoi(file);
	if (g_mapinfo.y <= 0)
		return (1);
	return (0);
}

int	is_wrong_file(int fd)
{
	int		byte;
	int		size;
	char	file[100];

	size = 0;
	while (1)
	{
		byte = read(fd, file + size, 1);
		if (file[size] == '\n')
			break ;
		size++;
		if (size == 100)
			return (1);
	}
	if (is_wrong_mapinfo(file, size))
		return (1);
	if (is_wrong_map(fd))
		return (1);
	return (0);
}

int	is_invalid_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_puterr();
		return (1);
	}
	if (is_wrong_file(fd))
	{
		ft_puterr();
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}