/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:18:39 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 11:02:52 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		g_max_length;
int		g_max_y;
int		g_max_x;
t_stack	*g_stack;

void	check_update(int past_index, int past_height, int index, int row)
{
	int	line_len;

	if (index - past_index - 1 > past_height)
		line_len = past_height;
	else
		line_len = index - past_index - 1;
	if (g_max_length < line_len)
	{
		g_max_length = line_len;
		g_max_y = row + 1 - line_len;
		g_max_x = past_index + 1;
	}
}

void	check_canpush(int index, int height, int row)
{
	int	past_index;
	int	past_height;

	if (g_stack->height < height)
	{
		stack_push(&g_stack, index, height);
	}
	else if (g_stack->height > height)
	{
		past_height = g_stack->height;
		stack_pop(&g_stack);
		past_index = g_stack->index;
		check_update(past_index, past_height, index, row);
		check_canpush(index, height, row);
	}
	else
	{
		stack_pop(&g_stack);
		stack_push(&g_stack, index, height);
	}
}

void	find_square_eachline(int y)
{
	int		idx_x;

	g_stack = stack_create_stack(-1, 0);
	idx_x = 0;
	while (idx_x < g_mapinfo.x)
	{
		check_canpush(idx_x, g_mapint[y][idx_x], y);
		idx_x++;
	}
	check_canpush(idx_x, 0, y);
	stack_free_all(g_stack);
	g_stack = 0;
}

void	find_square(void)
{
	int	idx_y;

	idx_y = 0;
	while (idx_y < g_mapinfo.y)
	{
		find_square_eachline(idx_y);
		idx_y++;
	}
	if (g_max_length != -1 && g_max_y != -1 && g_max_x != -1)
		make_map_answer(g_max_y, g_max_x, g_max_length);
}

void	solve(int fd)
{
	g_max_length = -1;
	g_max_y = -1;
	g_max_x = -1;
	make_map(fd);
	make_mapint();
	find_square();
	print_map();
	g_map_free_all(g_mapinfo.y);
	g_mapint_free_all(g_mapinfo.y);
}