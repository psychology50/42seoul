/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:02:15 by jayang            #+#    #+#             */
/*   Updated: 2022/02/22 12:02:26 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	make_histogram(int x)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (idx < g_mapinfo.y)
	{
		if (g_map[idx][x] == g_mapinfo.empty)
			count++;
		else
			count = 0;
		g_mapint[idx][x] = count;
		idx++;
	}
}

void	make_mapint(void)
{
	int	idx;

	g_mapint = (int **)malloc(sizeof(int *) * g_mapinfo.y);
	null_guard(1, -1);
	idx = 0;
	while (idx < g_mapinfo.y)
	{
		g_mapint[idx] = (int *)malloc(sizeof(int) * g_mapinfo.x);
		null_guard(1, idx);
		idx++;
	}
	idx = 0;
	while (idx < g_mapinfo.x)
	{
		make_histogram(idx);
		idx++;
	}
}

void	make_map_answer(int y, int x, int line)
{
	int	idx_y;
	int	idx_x;

	idx_y = 0;
	while (idx_y < line)
	{
		idx_x = 0;
		while (idx_x < line)
		{
			g_map[y + idx_y][x + idx_x] = g_mapinfo.full;
			idx_x++;
		}
		idx_y++;
	}
}

void	print_map(void)
{
	int	idx_y;
	int	idx_x;

	idx_y = 0;
	while (idx_y < g_mapinfo.y)
	{
		idx_x = 0;
		while (idx_x < g_mapinfo.x)
		{
			ft_putchar(g_map[idx_y][idx_x]);
			idx_x++;
		}
		ft_putchar('\n');
		idx_y++;
	}
}

void	make_map(int fd)
{
	int		idx;
	char	trash[1];

	g_map = (char **)malloc(sizeof(char *) * g_mapinfo.y);
	null_guard(0, -1);
	idx = 0;
	while (idx < g_mapinfo.y)
	{
		g_map[idx] = (char *)malloc(sizeof(char) * g_mapinfo.x);
		null_guard(0, idx);
		idx++;
	}
	idx = 0;
	while (1)
	{
		read(fd, trash, 1);
		if (trash[0] == '\n')
			break ;
	}
	while (idx < g_mapinfo.y)
	{
		read(fd, g_map[idx], g_mapinfo.x);
		read(fd, trash, 1);
		idx++;
	}
}